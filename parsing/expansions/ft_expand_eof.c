/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_eof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:41:07 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/20 14:52:31 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*	Enleve les quotes de debut et de fin	*/
static void	expand_quotes(char **s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 1;
	res = malloc(sizeof(char) * (ft_strlen(*s) - 1));
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

void	ft_expand_eof(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '"')
			expand_quotes(&tokens[i]);
		else if (tokens[i][0] == '\'')
			expand_quotes(&tokens[i]);
		i++;
	}
}
