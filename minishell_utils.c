/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:37:00 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/20 17:39:12 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_pacoshell(void)
{
	ft_printf("  8888888b.     d8888  .d8888b.   .d88888b.  d8b\n");
	ft_printf("  888   Y88b   d88888 d88P  Y88b d88P\" \"Y88b 88P\n");
	ft_printf("  888    888  d88P888 888    888 888     888 8P\n");
	ft_printf("  888   d88P d88P 888 888        888     888 \"  .d8888b\n");
	ft_printf("  8888888P\" d88P  888 888        888     888    88K\n");
	ft_printf("  888      d88P   888 888    888 888     888    \"Y8888b.\n");
	ft_printf("  888     d8888888888 Y88b  d88P Y88b. .d88P         X88\n");
	ft_printf("  888    d88P     888  \"Y8888P\"   \"Y88888P\"      88888P'\n");
	ft_printf("\n\n");
	ft_printf("     .d8888b.  888    888 8888888888 888      888\n");
	ft_printf("    d88P  Y88b 888    888 888        888      888\n");
	ft_printf("    Y88b.      888    888 888        888      888\n");
	ft_printf("     \"Y888b.   8888888888 8888888    888      888\n");
	ft_printf("        \"Y88b. 888    888 888        888      888\n");
	ft_printf("          \"888 888    888 888        888      888\n");
	ft_printf("    Y88b  d88P 888    888 888        888      888\n");
	ft_printf("     \"Y8888P\"  888    888 8888888888 88888888 88888888\n");
	ft_printf("\n");
}

void	free_line(t_minishell *shell)
{
	free(shell->line);
	ft_freeall(shell->tokens);
	if (((t_cmd_block *)shell->cmd_block->content)->in_fd != STDIN_FILENO)
		close(((t_cmd_block *)shell->cmd_block->content)->in_fd);
	if (((t_cmd_block *)shell->cmd_block->content)->out_fd != STDOUT_FILENO)
		close(((t_cmd_block *)shell->cmd_block->content)->out_fd);
	shell->tokens = NULL;
	shell->line = NULL;
}

void	init_shell(t_minishell *shell, char **env)
{
	ft_pacoshell();
	shell->tokens = NULL;
	shell->line = NULL;
	shell->alias = NULL;
	shell->env = NULL;
	rl_clear_history();
	shell->prompt = "pacoshell > ";
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
