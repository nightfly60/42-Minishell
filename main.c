/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:15:26 by edurance          #+#    #+#             */
/*   Updated: 2025/09/06 12:43:47 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_event = 0;

static void	pacoshell(t_minishell *shell)
{
	ft_alias_expansion(shell->tokens, shell->alias);
	ft_merge_tokens(shell);
	parse_pipeline(shell);
	ft_expand_cmds(shell);
	set_finals_fd(shell);
	if (shell->cmd_block)
		exit_wait(shell, exec_line(shell));
}

static void	handle_sigquit(t_minishell *shell)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	exit_minishell(shell);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*shell;

	(void)ac;
	(void)av;
	shell = malloc(sizeof(t_minishell));
	if (!shell)
		return (1);
	init_shell(shell, env);
	while (1)
	{
		shell->line = readline(shell->prompt);
		shell->tokens = get_tokens(shell->line);
		if (shell->line && shell->line[0])
			add_history((shell->line));
		if (parse_errors(shell))
			continue ;
		if (!(shell->line))
			handle_sigquit(shell);
		else if (shell->line[0])
			pacoshell(shell);
		init_signals();
		free_line(shell);
	}
	return (0);
}
