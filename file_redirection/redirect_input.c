/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:26:02 by edurance          #+#    #+#             */
/*   Updated: 2025/09/05 16:15:42 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

/*	redirige les entree pour les commandes et les pipes.	*/
int	redir_input(t_cmd_block *block)
{
	if (block->in_fd == 0 && block->pipe_fd != -1)
	{
		if (dup2(block->pipe_fd, STDIN_FILENO) == -1)
		{
			perror("dup2");
			return (1);
		}
		return (0);
	}
	if (block->in_fd < 0)
		return (1);
	if (dup2(block->in_fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		return (1);
	}
	return (0);
}
