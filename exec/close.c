/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:20:44 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/22 12:29:11 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*	Fermer les fd ouvert dans le fork fils.	*/
void	close_child(int pipes[2], t_list *cmd_block)
{
	t_list		*current;
	t_cmd_block	*content;

	current = cmd_block;
	close(pipes[0]);
	close(pipes[1]);
	while (current)
	{
		content = (t_cmd_block *)current->content;
		if (content->in_fd > 0)
			close(content->in_fd);
		if (content->out_fd > 1)
			close(content->out_fd);
		if (content->pipe_fd != -1)
			close(content->pipe_fd);
		current = current->next;
	}
}

/*	Fermer les fd ouvert et plus utilises dans le fork parent.	*/
void	close_parent(int pipas[2], t_cmd_block *command)
{
	close(pipas[1]);
	if (command->in_fd > 0)
		close(command->in_fd);
	if (command->out_fd > 1)
		close(command->out_fd);
	if (command->pipe_fd != -1)
		close(command->pipe_fd);
}
