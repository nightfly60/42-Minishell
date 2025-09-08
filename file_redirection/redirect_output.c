/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:37:57 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/22 12:30:08 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

/*	redirige les sorties pour les commandes et les pipes.	*/
int	redir_output(t_list *cmd_block, t_cmd_block *block, int pipes[2])
{
	if (!cmd_block->next || block->out_fd != STDOUT_FILENO)
	{
		if (block->out_fd < 0)
			return (1);
		if (dup2(block->out_fd, STDOUT_FILENO) == -1)
			perror("dup2");
	}
	else
	{
		if (dup2(pipes[1], STDOUT_FILENO) == -1)
			perror("dup2");
	}
	return (0);
}
