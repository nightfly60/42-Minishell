/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:56:05 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/04/26 14:18:28 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	i;
	char			*res;

	res = (char *)s;
	if (c >= 128)
		c = c % 128;
	i = ft_strlen(s) + 1;
	while (i > 0)
	{
		i--;
		if (res[i] == c)
			return (&res[i]);
	}
	return (0);
}
