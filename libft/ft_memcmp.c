/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:31:59 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/04/26 14:17:07 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, unsigned long n)
{
	unsigned long	i;
	unsigned char	*st1;
	unsigned char	*st2;

	if (n == 0)
		return (0);
	i = 0;
	st1 = ((unsigned char *)s1);
	st2 = ((unsigned char *)s2);
	while (st1[i] == st2[i] && i < n - 1)
		i++;
	return (st1[i] - st2[i]);
}
