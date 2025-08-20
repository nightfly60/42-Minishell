/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:26:02 by edurance          #+#    #+#             */
/*   Updated: 2025/08/20 15:59:48 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

void redirect_input(void *content)
{
	int old_fd;
	t_redir *in;

	in = (t_redir *)content;
	ft_printf("%p\n", in);
	if (in->type == INFILE)
	{
		ft_printf("%s\n", in->name);
		old_fd = open_files(in->name, in->type);
	}
	else
		old_fd = ft_heredoc(in->name);
	if (dup2(old_fd, STDIN_FILENO) == -1)
		perror("dup2");
	close(old_fd);
}
