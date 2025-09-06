/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:49:20 by edurance          #+#    #+#             */
/*   Updated: 2025/09/06 18:45:50 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_files(void *redir)
{
	t_redir	*redirections;

	redirections = (t_redir *)redir;
	free(redirections->name);
	redirections->name = NULL;
	free(redir);
	redir = NULL;
}

static void	free_cmd_block(void *command)
{
	t_cmd_block	*cmd;

	cmd = (t_cmd_block *)command;
	ft_freeall(cmd->cmds);
	cmd->cmds = NULL;
	ft_lstclear(&(cmd->redir), &free_files);
	cmd->redir = NULL;
	free(command);
	command = NULL;
}

void	free_line(t_minishell *shell)
{
	free(shell->line);
	ft_freeall(shell->tokens);
	shell->tokens = NULL;
	shell->line = NULL;
	ft_lstclear(&(shell->cmd_block), &free_cmd_block);
	shell->cmd_block = NULL;
}
