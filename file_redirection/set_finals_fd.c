/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_finals_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:36:49 by edurance          #+#    #+#             */
/*   Updated: 2025/09/05 14:11:58 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

static void	set_infile_fd(t_cmd_block *block, t_minishell *shell)
{
	t_redir	*redir;
	t_list	*current;

	current = block->in;
	while (current)
	{
		if (block->in_fd != STDIN_FILENO)
			close(block->in_fd);
		redir = (t_redir *)current->content;
		if (redir->type == INFILE)
		{
			block->in_fd = open_files(redir->name, redir->type);
		}
		else
			block->in_fd = ft_heredoc(redir->name, shell, redir->type);
		current = current->next;
	}
}

static void	set_outfile_fd(t_cmd_block *block)
{
	t_redir	*redir;
	t_list	*current;

	current = block->out;
	while (current)
	{
		if (block->out_fd != STDOUT_FILENO)
			close(block->out_fd);
		redir = (t_redir *)current->content;
		block->out_fd = open_files(redir->name, redir->type);
		current = current->next;
	}
}

void	set_finals_fd(t_minishell *shell)
{
	t_cmd_block	*block;
	t_list		*lst;

	lst = shell->cmd_block;
	while (lst)
	{
		block = ((t_cmd_block *)lst->content);
		set_infile_fd(block, shell);
		set_outfile_fd(block);
		lst = lst->next;
	}
}
