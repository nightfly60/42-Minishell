/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:03:18 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/15 12:33:20 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*check si char *s commence par un operateur (on check les plus longs
	en premiers, ex.: eviter que << soit pris pour <)*/
int	is_operator(char *s)
{
	if (!ft_strncmp(s, "<<", 2))
		return (2);
	if (!ft_strncmp(s, ">>", 2))
		return (2);
	if (!ft_strncmp(s, "<", 1))
		return (1);
	if (!ft_strncmp(s, ">", 1))
		return (1);
	if (!ft_strncmp(s, "|", 1))
		return (1);
	return (0);
}

/*check si char *s commence par une quote et renvoie la longueur de la quote*/
int	is_quote(char *s)
{
	int		i;
	char	quote;

	i = 0;
	if (s[i] == '"' || s[i] == '\'')
	{
		quote = s[i];
		i++;
		while (s[i] && s[i] != quote)
			i++;
		if (s[i] == '"' || s[i] == '\'')
			i++;
	}
	return (i);
}
