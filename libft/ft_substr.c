/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:15:42 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/04/26 14:18:37 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned long len)
{
	char			*res;
	unsigned long	i;
	unsigned long	n;

	if (start >= ft_strlen(s))
		n = 1;
	else if (len > ft_strlen(s + start))
		n = ft_strlen(s + start) + 1;
	else
		n = len + 1;
	res = malloc(sizeof(char) * n);
	if (!res)
		return (NULL);
	res[0] = '\0';
	if (start >= ft_strlen(s))
		return (res);
	i = 0;
	while (i < len && s[i + start])
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
