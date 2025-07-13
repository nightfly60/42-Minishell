/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:08:19 by edurance          #+#    #+#             */
/*   Updated: 2025/05/27 12:01:39 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// verifie si il y a un \n dans la string et renvoie sa position
int	isnornot(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

// rem + buffer
void	actualrem(char **rem, char *add)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * (ft_strlen(*rem) + ft_strlen(add) + 1));
	if (!dest)
		return ;
	i = 0;
	j = 0;
	while (*rem && (*rem)[i])
	{
		dest[i] = (*rem)[i];
		i++;
	}
	while (add[j])
	{
		dest[i] = add[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (*rem)
		free(*rem);
	*rem = dest;
}

// rem = rem a partir de la premiere occurence du \n
void	newrem(char **rem)
{
	char	*temp;
	int		i;
	int		len;

	len = isnornot(*rem);
	temp = malloc(sizeof(char) * (ft_strlen(*rem) - len + 1));
	if (!temp)
	{
		free(*rem);
		*rem = NULL;
		return ;
	}
	i = -1;
	while ((*rem)[++i + len])
		temp[i] = (*rem)[i + len];
	temp[i] = '\0';
	free(*rem);
	if (temp[0] == '\0')
	{
		free(temp);
		temp = NULL;
	}
	*rem = temp;
}

// res = rem jusqu'au \n
void	mkres(char **res, char *rem, int len)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
	{
		*res = NULL;
		return ;
	}
	i = 0;
	while (i < len)
	{
		dest[i] = rem[i];
		i++;
	}
	dest[i] = '\0';
	*res = dest;
}
