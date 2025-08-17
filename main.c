/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:15:26 by edurance          #+#    #+#             */
/*   Updated: 2025/08/17 15:28:55 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_minishell(t_minishell *shell)
{
	ft_freeall(shell->tokens);
	free(shell->line);
	rl_clear_history();
	clear_alias(shell->alias, &free);
	clear_env(shell->env, &free);
	free(shell);
	ft_printf("exit\n");
	exit(0);
}

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

static void	init_shell(t_minishell *shell, char **env)
{
	shell->tokens = NULL;
	shell->line = NULL;
	shell->alias = NULL;
	shell->env = NULL;
	rl_clear_history();
	shell->prompt = "minishell > ";
	copy_env(shell, env);
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
		if (!(shell->line) || !ft_strcmp((shell->line), "exit"))
		{
			exit_minishell(shell);
		}
		add_history((shell->line));
		if (!quotes_checker((shell->line)))
		{
			ft_printf("minishell: %s: syntax error\n", (shell->line));
			free((shell->line));
			(shell->line) = NULL;
			continue ;
		}
		if (!ft_strncmp((shell->line), "alias", 5))
		{
			ft_alias(ft_split((shell->line), ' '), &(shell->alias));
		}
		else if (!ft_strncmp((shell->line), "env", 3))
			print_env(shell);
		else
		{
			shell->tokens = get_tokens(shell->line);
			print_str_table(shell->tokens);
			ft_printf("\n\n");
			ft_alias_expansion(shell->tokens, shell->alias);
			ft_expand_tokens(shell->tokens, shell->env);
			print_str_table(shell->tokens);
		}
		free(shell->line);
		shell->line = NULL;
	}
	rl_clear_history();
	return (0);
}
