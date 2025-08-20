/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:25:20 by edurance          #+#    #+#             */
/*   Updated: 2025/08/20 15:57:06 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

int	ft_heredoc(char *limiter)
{
	char	*line;
	char	*text;
	int		limit_len;
	int		fd[2];

	line = NULL;
	text = NULL;
	limit_len = ft_strlen(limiter);
	if (pipe(fd) == -1)
		perror("pipe");
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line || (!ft_strncmp(limiter, line, limit_len)
				&& line[limit_len] == '\n'))
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	get_next_line(-1);
	close(fd[1]);
	return (fd[0]);
}
