/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:13:27 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/04/26 13:28:01 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countlen(int nbr)
{
	long	n;
	int		count;

	count = 0;
	n = (long)nbr;
	if (n <= 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*res;
	int		lenn;

	lenn = countlen(n);
	nbr = (long)n;
	res = malloc(sizeof(char) * (lenn + 1));
	if (!res)
		return (NULL);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	res[lenn] = '\0';
	lenn--;
	if (nbr == 0)
		res[0] = '0';
	while (lenn >= 0 && nbr != 0)
	{
		res[lenn] = nbr % 10 + '0';
		nbr = nbr / 10;
		lenn--;
	}
	return (res);
}
