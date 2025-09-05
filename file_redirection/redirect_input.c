/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:26:02 by edurance          #+#    #+#             */
/*   Updated: 2025/09/05 14:12:39 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

/*	redirige les entree pour les commandes et les pipes.	*/
void	redir_input(t_cmd_block *block, t_minishell *shell)
{
	if (block->in_fd == 0 && block->pipe_fd != -1)
	{
		if (dup2(block->pipe_fd, STDIN_FILENO) == -1)
			perror("dup2");
		return ;
	}
	if (block->in_fd < 0)
		exit_minishell(shell);
	if (dup2(block->in_fd, STDIN_FILENO) == -1)
		perror("dup2");
}
