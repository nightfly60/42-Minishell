/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:37:57 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/20 15:15:35 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

void	redirect_output(void *content)
{
	t_redir *out;
	int	old_fd;

	out = (t_redir *)content;
	old_fd = open_files(out->name, out->type);
	if (dup2(old_fd, STDOUT_FILENO) == -1)
		perror(errno);
	close(old_fd);
}
