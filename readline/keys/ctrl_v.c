/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:09:49 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/11 15:15:04 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

int	ctrl_v(char c)
{
	static int	status = 0;

	if (c == 22)
	{
		if (status)
		{
			ft_printf("^V");
			status = 0;
			return (1);
		}
		else
			return (++status);
	}
	else
		status = 0;
	return (0);
}
