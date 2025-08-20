/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:33:11 by edurance          #+#    #+#             */
/*   Updated: 2025/08/20 11:16:43 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*On join les tokens tant qu'on arrive pas sur un espace.*/
static char	*merge_until_space(char *line, int *line_i, char **tokens, int *i)
{
	char	*merged;
	char	*temp;

	if (is_operator(tokens[*i]))
	{
		merged = ft_strdup(tokens[*i]);
		*line_i += ft_strlen(tokens[*i]);
		(*i)++;
		return (merged);
	}
	merged = ft_strdup(tokens[*i]);
	*line_i += ft_strlen(tokens[*i]);
	(*i)++;
	while (tokens[*i] && line[*line_i] && !ft_isspace(line[*line_i])
		&& !is_operator(&line[*line_i]) && !is_operator(tokens[*i]))
	{
		temp = ft_strjoin(merged, tokens[*i]);
		free(merged);
		merged = temp;
		*line_i += ft_strlen(tokens[*i]);
		(*i)++;
	}
	return (merged);
}

/*Join les tokens qui devraient n'en faire qu'un comment "salut"atous.*/
void	ft_merge_tokens(t_minishell *shell)
{
	char	**res;
	int		i;
	int		res_i;
	int		line_i;
	int		nb_tokens;

	i = 0;
	res_i = 0;
	line_i = 0;
	nb_tokens = ft_arrlen(shell->tokens);
	res = malloc(sizeof(char *) * (nb_tokens + 1));
	if (!res)
		return ;
	while (i < nb_tokens)
	{
		while ((shell->line)[line_i] && (ft_isspace(shell->line[line_i])))
			line_i++;
		res[res_i] = merge_until_space(shell->line, &line_i, shell->tokens, &i);
		res_i++;
	}
	res[res_i] = NULL;
	ft_freeall(shell->tokens);
	shell->tokens = res;
	return ;
}
