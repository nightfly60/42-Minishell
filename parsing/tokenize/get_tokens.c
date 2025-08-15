/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:07:40 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/15 15:54:22 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*	retourne la longeur entre s[0] et la fin ou
	le prochain espace de char *s	*/
static int	ft_strlen_to_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !ft_isspace(s[i]) && !is_operator(&s[i]))
		i++;
	return (i);
}

/*	util pour next_token, rend la taille du token	*/
static int	len_next_token(char *s)
{
	int	i;
	int	quote_index;
	int	operator_index;

	i = 0;
	quote_index = is_quote(s);
	operator_index = is_operator(s);
	if (quote_index)
		i = quote_index;
	else if (operator_index)
		i = operator_index;
	else
		i = ft_strlen_to_space(s);
	return (i);
}

/*	fonction qui renvoie le premier token de char *s malloc en (char *)	*/
static char	*next_token(char *s)
{
	int		i;
	char	*res;
	int		j;

	j = 0;
	i = len_next_token(s);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = 0;
	while (j < i)
	{
		res[j] = s[j];
		j++;
	}
	return (res);
}

/*	renvoie un (char **) NULL termine,
	avec tous les token de la line passee en argument	*/
/*	NB: tokens = words, quotes, dquotes et operators	*/
char	**get_tokens(char *line)
{
	char	**res;
	int		i;
	int		j;

	j = 0;
	res = malloc(sizeof(char *) * (count_tokens(line) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (line[i])
	{
		while (line[i] && ft_isspace(line[i]) && !is_operator(&line[i])
			&& !is_quote(&line[i]))
			i++;
		if (!line[i])
			break ;
		res[j] = next_token(&line[i]);
		j++;
		i += len_next_token(&line[i]);
	}
	res[count_tokens(line)] = NULL;
	return (res);
}
