/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:08:13 by edurance          #+#    #+#             */
/*   Updated: 2025/05/27 12:01:05 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(int fd, char **rem)
{
	int		bytes;
	char	*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	ft_bzero(buf, BUFFER_SIZE + 1);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes == -1)
	{
		free(*rem);
		*rem = NULL;
	}
	if (bytes <= 0)
	{
		free(buf);
		buf = NULL;
		return (0);
	}
	actualrem(rem, buf);
	free(buf);
	buf = NULL;
	return (bytes);
}

static char	*freeall(char ***rem, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (fd < 0 || fd > 1023)
		return (NULL);
	free((*rem)[fd]);
	(*rem)[fd] = NULL;
	while (i <= 1023)
	{
		if ((*rem)[i])
			j++;
		i++;
	}
	if (j == 0)
	{
		free(*rem);
		*rem = NULL;
	}
	return (NULL);
}

static void	mallocrem(char ***rem)
{
	int	i;

	i = 0;
	if (*rem)
		return ;
	*rem = malloc(sizeof(char *) * 1024);
	if (!*rem)
		return ;
	while (i <= 1023)
	{
		(*rem)[i] = NULL;
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	**rem = NULL;

	mallocrem(&rem);
	if (fd < 0 || fd > 1023)
		return (freeall(&rem, fd));
	ft_read(fd, &rem[fd]);
	if ((!rem[fd] || rem[fd][0] == '\0'))
		return (freeall(&rem, fd));
	while (!isnornot(rem[fd]) && ft_read(fd, &rem[fd]) == BUFFER_SIZE)
		;
	if (isnornot(rem[fd]))
	{
		mkres(&res, rem[fd], isnornot(rem[fd]));
		newrem(&rem[fd]);
		return (res);
	}
	mkres(&res, rem[fd], ft_strlen(rem[fd]));
	freeall(&rem, fd);
	return (res);
}
