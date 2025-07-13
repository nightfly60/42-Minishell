/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:26:22 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/04/26 14:16:34 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned long nmemb, unsigned long size)
{
	void			*res;
	unsigned long	totalbytes;

	totalbytes = nmemb * size;
	if (totalbytes > 2147483647)
		return (NULL);
	res = malloc(totalbytes);
	if (!res)
		return (NULL);
	ft_memset(res, 0, totalbytes);
	return (res);
}
