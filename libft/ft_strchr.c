/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:44:47 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/04/26 14:17:42 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;
	char			*res;

	if (c >= 128)
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
