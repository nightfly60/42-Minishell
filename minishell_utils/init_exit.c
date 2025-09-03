/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:37:00 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/03 16:12:24 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	init_shell(t_minishell *shell, char **env)
{
	ft_pacoshell();
	shell->tokens = NULL;
	shell->line = NULL;
	shell->alias = NULL;
	shell->env = NULL;
	shell->cmd_block = NULL;
	shell->exit_status = 0;
	rl_clear_history();
	shell->prompt = "pacoshell> ";
	shell->pwd = getcwd(NULL, 0);
	copy_env(shell, env);
	create_env(shell, env);
}

void	exit_minishell(t_minishell *shell, int exit_code)
{
	free_line(shell);
	rl_clear_history();
	clear_alias(shell->alias, &free);
	clear_env(shell->env, &free);
	free(shell->pwd);
	free(shell);
	exit(exit_code);
}
