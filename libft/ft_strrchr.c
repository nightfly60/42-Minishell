/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:55:29 by edurance          #+#    #+#             */
/*   Updated: 2025/04/26 14:18:22 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;

	c = c % 128;
	i = ft_strlen(s) + 1;
	res = (char *)s;
	while (i > 0)
	{
		i--;
		if (res[i] == c)
			return (&res[i]);
	}
	return (0);
}
