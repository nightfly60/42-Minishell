/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:20:44 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/06 12:50:54 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static void	ft_close(int fd)
{
	if (fd < 0)
		return ;
	close(fd);
}

/*	Fermer les fd ouvert dans le fork fils.	*/
void	close_child(int pipes[2], t_list *cmd_block)
{
	t_list		*current;
	t_cmd_block	*content;

	current = cmd_block;
	ft_close(pipes[0]);
	ft_close(pipes[1]);
	while (current)
	{
		content = (t_cmd_block *)current->content;
		if (content->in_fd > 0)
			ft_close(content->in_fd);
		if (content->out_fd > 1)
			ft_close(content->out_fd);
		if (content->pipe_fd != -1)
			ft_close(content->pipe_fd);
		current = current->next;
	}
}

/*	Fermer les fd ouvert et plus utilises dans le fork parent.	*/
void	close_parent(int pipas[2], t_cmd_block *command)
{
	ft_close(pipas[1]);
	if (command->in_fd > 0)
		ft_close(command->in_fd);
	if (command->out_fd > 1)
		ft_close(command->out_fd);
	if (command->pipe_fd != -1)
		ft_close(command->pipe_fd);
}
