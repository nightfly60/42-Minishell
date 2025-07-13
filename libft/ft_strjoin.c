/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:25:12 by edurance          #+#    #+#             */
/*   Updated: 2025/05/27 12:07:08 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	lenloc(const char *s1, const char *s2)
{
	return (ft_strlen(s1) + ft_strlen(s2) + 1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*res;
	unsigned long	i;
	unsigned long	j;

	res = malloc(sizeof(char) * lenloc(s1, s2));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
