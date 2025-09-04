/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_even.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:24:24 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 17:11:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*Est ce que ce nombre est pair ou impair. even = pair / odd = impair.*/
int	is_even(int n)
{
	if (n % 2 == 0)
		return (1);
	return (0);
}
