/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:43:25 by edurance          #+#    #+#             */
/*   Updated: 2025/09/03 15:05:10 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	exit_wait(t_minishell *shell, int last)
{
	int	pid;
	int	status;
	int	last_status;
	int	sigint_received;

	last_status = 0;
	sigint_received = 0;
	pid = 0;
	signal(SIGINT, SIG_IGN);
	while ((pid = waitpid(0, &status, 0)) > 0)
	{
		if (pid == last)
			last_status = status;
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
			sigint_received = 1;
	}
	if (sigint_received)
		write(1, "\n", 1);
	shell->exit_status = WEXITSTATUS(last_status);
}
