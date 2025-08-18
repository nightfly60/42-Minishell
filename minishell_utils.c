/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:37:00 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/18 15:39:06 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_line(t_minishell *shell)
{
	free(shell->line);
	ft_freeall(shell->tokens);
	shell->tokens = NULL;
	shell->line = NULL;
}

void	init_shell(t_minishell *shell, char **env)
{
	shell->tokens = NULL;
	shell->line = NULL;
	shell->alias = NULL;
	shell->env = NULL;
	rl_clear_history();
	shell->prompt = "minishell > ";
	copy_env(shell, env);
}

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
