/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:24:02 by edurance          #+#    #+#             */
/*   Updated: 2025/08/10 18:46:01 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

/*Retire le char de l'indexe passe en argument et decale le reste de la liste. (index pour BackSpace et index + 1 pour delete)*/
void	delete_char(char *buf, int index)
{
	int	len;
	int	i;

	len = ft_strlen(buf);
	i = index;
	if (!buf || index < 0 || index > len)
		return ;
	while (buf[i] && buf[i + 1])
	{
		buf[i] = buf[i + 1];
		i++;
	}
	buf[i] = '\0';
}
