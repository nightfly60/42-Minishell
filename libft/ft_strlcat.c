/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:06:32 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/04/26 14:18:06 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long siz)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	destlen;

	i = ft_strlen(dst);
	j = 0;
	destlen = i;
	if (siz <= destlen)
		return (ft_strlen(src) + siz);
	while (i < siz - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + destlen);
}
