/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:31:28 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/16 15:11:00 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static void	single_quote(char **s)
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
	ft_printf("|%s|\n", *s);
	free(*s);
	*s = res;
	ft_printf("|%s|\n", *s);
}

static int	expand_len(char *s, t_env *first)
{
	int	i;
	int	len;
	int	valid_id;

	i = 1;
	len = 0;
	while (s[i] && s[i + 1])
	{
		if (s[i] == '$' && s[i + 1] && is_valid_id(&s[i + 1]))
		{
			valid_id = is_valid_id(&s[i + 1]);
			if (find_var(&s[i + 1], &first, valid_id) && find_var(&s[i + 1],
					&first, valid_id)->value)
				len += ft_strlen(find_var(&s[i + 1], &first, valid_id)->value);
			i += valid_id + 1;
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}

static void	double_quote(char **s, t_env *env)
{
	char	*res;
	int		i;
	int		j;
	t_env	*temp;

	i = 0;
	ft_printf("%d\n", expand_len(*s, env));
	res = malloc(sizeof(char) * expand_len(*s, env) + 1);
	if (!res)
		return ;
	while ((*s)[i] && (*s)[i + 1])
	{
		if ((*s)[i] == '$' && (*s)[i + 1] && is_valid_id(&(*s)[i + 1]))
		{
			j = 0;
			temp = find_var(&(*s)[i + 1], &env, is_valid_id(&(*s)[i + 1]));
			while (temp && (temp->value)[j])
			{
				res[i] = (temp->value)[j];
				i++;
				j++;
			}
		}
		else
			i++;
	}
	res[i] = 0;
	free(*s);
	*s = res;
}

static void	expand_quote(char **quote, t_env *env)
{
	if ((*quote)[0] == '\'')
		single_quote(quote);
	else
		double_quote(quote, env);
}

void	ft_quotes_expansion(char **tokens, t_env *env)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '"' || tokens[i][0] == '\'')
		{
			expand_quote(&tokens[i], env);
			ft_printf("|%s|\n", tokens[i]);
		}
		i++;
	}
}
