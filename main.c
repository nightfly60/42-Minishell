/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:15:26 by edurance          #+#    #+#             */
/*   Updated: 2025/09/03 15:16:05 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (signal == SIGQUIT)
		return ;
}

void	exit_wait(t_minishell *shell, int last)
{
	int	pid;
	int	status;
	int	last_status;

	pid = 0;
	while (pid != -1)
	{
		pid = waitpid(0, &status, 0);
		if (pid == last)
			last_status = status;
	}
	shell->exit_status = (WEXITSTATUS(last_status));
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*shell;

	(void)ac;
	(void)av;
	shell = malloc(sizeof(t_minishell));
	if (!shell)
		return (1);
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	init_shell(shell, env);
	while (1)
	{
		shell->line = readline(shell->prompt);
		add_history((shell->line));
		shell->tokens = get_tokens(shell->line);
		if (parse_errors(shell))
			continue ;
		if (!(shell->line) || !ft_strcmp((shell->line), "exit"))
			exit_minishell(shell, 0);
		else if (!ft_strncmp((shell->line), "alias", 5))
		{
			ft_alias(ft_split((shell->line), ' '), &(shell->alias));
		}
		else if (!ft_strncmp((shell->line), "env", 3))
			print_env(shell);
		else
		{
			ft_alias_expansion(shell->tokens, shell->alias);
			ft_merge_tokens(shell);
			parse_pipeline(shell);
			ft_expand_cmds(shell);
			// ft_lstiter(shell->cmd_block, &print_cmd);
			set_finals_fd(shell);
			if (shell->cmd_block)
				exit_wait(shell, exec_line(shell));
		}
		// ft_lstiter(shell->cmd_block, &print_cmd);
		free_line(shell);
	}
	return (0);
}
