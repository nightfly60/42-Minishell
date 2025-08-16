/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:34:27 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/16 11:45:40 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

/*	Renvoie la taille d'un id valide.	*/
int	is_valid_id(char *s)
{
	int	i;

	i = 0;
	if (s[i] != '_' && !ft_isalpha(s[i]))
		return (0);
	while (s[i])
	{
		if (s[i] != '_' && !ft_isalnum(s[i]))
			return (i);
		i++;
	}
	return (i);
}
