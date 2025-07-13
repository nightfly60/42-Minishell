/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:10:10 by edurance          #+#    #+#             */
/*   Updated: 2025/04/26 14:16:45 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	unsigned long	i;
	unsigned char	*res;
	unsigned char	lettre;

	i = 0;
	res = (unsigned char *)s;
	lettre = (unsigned char)c;
	while (i < n)
	{
		if (res[i] == lettre)
			return (&res[i]);
		i++;
	}
	return (0);
}
