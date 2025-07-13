/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:26:57 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/04/26 14:17:04 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	unsigned long	i;
	unsigned char	l;
	unsigned char	*res;

	i = 0;
	res = ((unsigned char *)s);
	l = ((unsigned char)c);
	while (i < n)
	{
		if (res[i] == l)
			return (&res[i]);
		i++;
	}
	return (0);
}
