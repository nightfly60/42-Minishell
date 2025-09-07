/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_finals_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:36:49 by edurance          #+#    #+#             */
/*   Updated: 2025/09/06 22:37:03 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

static void	set_infile_fd(t_redir *redir, t_minishell *shell,
		t_cmd_block *block)
{
	if (block->in_fd != STDIN_FILENO && block->in_fd > 0)
		close(block->in_fd);
	if (!block->is_valid)
		return ;
	if (redir->type == INFILE)
	{
		block->in_fd = open_files(redir->name, redir->type, shell);
		if (block->in_fd == -1)
		{
			block->is_valid = 0;
			return ;
		}
	}
	else
		block->in_fd = ft_heredoc(redir->name, shell, redir->type);
}

static void	set_outfile_fd(t_redir *redir, t_minishell *shell,
		t_cmd_block *block)
{
	if (block->out_fd != STDOUT_FILENO && block->out_fd > 0)
		close(block->out_fd);
	if (!block->is_valid)
		return ;
	block->out_fd = open_files(redir->name, redir->type, shell);
	if (block->out_fd == -1)
	{
		block->is_valid = 0;
		return ;
	}
}

static void	redirect_fd(t_cmd_block *block, t_minishell *shell)
{
	t_list	*lst;
	t_redir	*redir;

	lst = block->redir;
	while (lst)
	{
		redir = (t_redir *)lst->content;
		if (redir->type == HEREDOC || redir->type == HEREDOC_NO_EXP)
			set_infile_fd(redir, shell, block);
		lst = lst->next;
	}
	lst = block->redir;
	while (lst)
	{
		redir = (t_redir *)lst->content;
		if (redir->type == INFILE)
			set_infile_fd(redir, shell, block);
		else if (redir->type != HEREDOC && redir->type != HEREDOC_NO_EXP)
			set_outfile_fd(redir, shell, block);
		lst = lst->next;
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
		redirect_fd(block, shell);
		lst = lst->next;
	}
}
