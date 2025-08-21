/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:15:26 by edurance          #+#    #+#             */
/*   Updated: 2025/08/20 18:31:26 by aabouyaz         ###   ########.fr       */
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

static void redirection(int in, int out)
{
	char *line;

	line = get_next_line(in);
	while (line)
	{
		ft_putstr_fd(line, out);
		free(line);
		line = get_next_line(in);
	}
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
			exit_minishell(shell);
		if (!ft_strncmp((shell->line), "alias", 5))
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
			ft_lstiter(shell->cmd_block, &print_cmd);
		}
		set_finals_fd(shell);
		redirection(((t_cmd_block *)shell->cmd_block->content)->in_fd, ((t_cmd_block *)shell->cmd_block->content)->out_fd);
		ft_lstiter(shell->cmd_block, &print_cmd);
		free_line(shell);
	}
	return (0);
}
