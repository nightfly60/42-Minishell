/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:37:19 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/27 11:27:53 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned(unsigned long long n, int *add)
{
	unsigned int	nbr;

	nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr_unsigned(nbr / 10, add);
	*add = *add + ft_putchar((nbr % 10) + '0');
}
