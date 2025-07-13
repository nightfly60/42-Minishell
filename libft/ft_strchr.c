/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:50:40 by edurance          #+#    #+#             */
/*   Updated: 2025/04/27 13:12:57 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;
	char			*res;

	c = c % 128;
	i = 0;
	res = (char *)s;
	while (i <= ft_strlen(res))
	{
		if (res[i] == c)
			return (&res[i]);
		i++;
	}
	return (0);
}
