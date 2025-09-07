/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:43:25 by edurance          #+#    #+#             */
/*   Updated: 2025/09/07 11:12:49 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static int	handle_sig_child(int status, t_minishell *shell)
{
	if (WTERMSIG(status) == SIGINT)
	{
		shell->exit_status = 130;
		write(1, "\n", 1);
	}
	else if (WTERMSIG(status) == SIGQUIT)
	{
		shell->exit_status = 131;
		write(1, "Quit (core dumped)\n", 19);
	}
	else
		return (0);
	return (1);
}

void	exit_wait(t_minishell *shell, int last)
{
	int	pid;
	int	status;
	int	last_status;
	int	sig_received;

	if (last < 0)
		return ;
	last_status = 0;
	sig_received = 0;
	pid = 0;
	status = 0;
	signal(SIGINT, SIG_IGN);
	while (pid != -1)
	{
		pid = waitpid(0, &status, 0);
		if (pid == last)
			last_status = status;
		if (WIFSIGNALED(status) && pid != -1)
			sig_received = handle_sig_child(status, shell);
	}
	if (!sig_received)
		shell->exit_status = WEXITSTATUS(last_status);
}
