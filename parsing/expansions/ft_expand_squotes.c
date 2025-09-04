/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_squotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:15:51 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 17:11:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*	Expand et remplace l'adresse du char **s envoye.
	Comportement d'une single_quote uniquement.	*/
void	single_quote(char **s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 1;
	res = malloc(sizeof(char) * (ft_strlen(*s) - 1));
	if (!res)
		return ;
	while ((*s)[i] != '\'')
	{
		res[j] = (*s)[i];
		i++;
		j++;
	}
	res[j] = 0;
	free(*s);
	*s = res;
}
