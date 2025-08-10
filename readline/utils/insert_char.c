/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:26:38 by edurance          #+#    #+#             */
/*   Updated: 2025/08/10 13:26:54 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

void	insert_char(char *buf, char c, int index)
{
	int	len;
	int	i;

	len = ft_strlen(buf);
	i = len;
	if (!buf || index < 0 || index > len || len >= BUF_MAX - 1)
		return ;
	while (i >= index)
	{
		buf[i + 1] = buf[i];
		i--;
	}
	buf[index] = c;
	buf[len + 1] = '\0';
}
