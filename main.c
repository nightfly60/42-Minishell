/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:21:40 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/13 16:47:23 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	quotingquoterquote(char ccc, char *c, char *gcc)
{
	if (ccc == '\'')
		*c = ccc;
	else
		*c = ccc;
	if (ccc == '\'')
		*gcc = '\"';
	else
		*gcc = '\'';
}

int	check_quote(char *s)
{
	int		i;
	char	quote;
	char	autre;
	int		count;

	i = 0;
	while (s[i])
	{
		if (s[i] && (s[i] == '\'' || s[i] == '\"'))
		{
			count = 0;
			quotingquoterquote(s[i], &quote, &autre);
			i++;
			while (s[i])
			{
				if (s[i] == quote)
				{
					i++;
					break;
				}
				if (s[i] == autre)
					count++;
				i++;
			}
			if (count % 2 != 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int check_quote2(char *s)
{
	int	i;
	int	dquote;
	int quote;

	i = 0;
	dquote = 0;
	quote = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			quote++;
		if (s[i] == '\"')
			dquote++;
		i++;
	}
	if ((quote % 2) || (dquote % 2))
		return (0);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	char	*line;

	(void)env;
	(void)av;
	if (ac != 1)
		return (ft_printf("bon bon bon\n"));
	line = "\"\'\"\'";
	ft_printf("%d et |%s|\n", check_quote(line) && check_quote2(line), line);
	return (0);
}
