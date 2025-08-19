/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:15:51 by edurance          #+#    #+#             */
/*   Updated: 2025/08/19 12:19:42 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*	Expand et remplace l'adresse du char **s envoye.
	Comportement d'une single_quote uniquement.	*/
void	single_quote(char **s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 1;
	res = malloc(sizeof(char) * (strlen(*s) - 1));
	if (!res)
		return ;
	while ((*s)[i] && (*s)[i + 1])
	{
		res[j] = (*s)[i];
		i++;
		j++;
	}
	res[j] = 0;
	free(*s);
	*s = res;
}
