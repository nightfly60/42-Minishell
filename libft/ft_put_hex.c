/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:19:57 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/27 11:29:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_hex(long nbr, int caps, int *add)
{
	char			*dict;
	char			c;
	unsigned int	n;

	n = (unsigned int)nbr;
	if (!caps)
		dict = "0123456789abcdef";
	else
		dict = "0123456789ABCDEF";
	c = dict[n % 16];
	if (n / 16)
		ft_put_hex(n / 16, caps, add);
	*add = *add + ft_putchar(c);
}
