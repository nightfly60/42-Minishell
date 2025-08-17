/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:31:28 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/17 12:52:35 by aabouyaz         ###   ########.fr       */
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
	free(*s);
	*s = res;
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
			if (find_var_len(&s[i + 1], &first, valid_id) && find_var_len(&s[i
					+ 1], &first, valid_id)->value)
				len += ft_strlen(find_var_len(&s[i + 1], &first,
							valid_id)->value);
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

static void	set_value(t_env *env, char *s, char **res, int *index)
{
	t_env	*temp;
	char	buffer[4096];
	int		i;
	int		id_len;

	i = 0;
	id_len = is_valid_id(s);
	while (i < id_len)
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = 0;
	temp = find_var(buffer, &env);
	if (!temp || !temp->value)
		return ;
	i = 0;
	while ((temp->value)[i])
	{
		(*res)[(*index)] = (temp->value)[i];
		i++;
		(*index)++;
	}
}

static void	double_quote(char **s, t_env *env)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 1;
	res = malloc(sizeof(char) * expand_len(*s, env) + 1);
	if (!res)
		return ;
	while ((*s)[i] && (*s)[i + 1])
	{
		if ((*s)[i] == '$' && (*s)[i + 1] && is_valid_id(&(*s)[i + 1]))
		{
			set_value(env, &(*s)[i + 1], &res, &j);
			i += is_valid_id(&(*s)[i + 1]) + 1;
		}
		else
		{
			res[j++] = (*s)[i];
			i++;
		}
	}
	res[j] = 0;
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
		}
		i++;
	}
}
