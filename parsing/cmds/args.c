/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:01:30 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 17:11:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*Compte le nombres d'arguments (cmd + args jusqu'au prochain operateur).*/
int	count_cmd_args(char **tokens, int i)
{
	int	arg_count;

	arg_count = 0;
	while (tokens[i + arg_count] && ft_strcmp(tokens[i + arg_count], "|"))
	{
		if (!is_operator(tokens[i + arg_count]))
			arg_count++;
		else
			i += 2;
	}
	return (arg_count);
}

/*Duplique tant d'arguments dans un char ***/
char	**ft_argdup(char **tokens, int arg_count, int i)
{
	char	**args;
	int		j;

	j = 0;
	args = malloc(sizeof(char *) * (arg_count + 1));
	if (!args)
		return (NULL);
	while (j < arg_count)
	{
		args[j] = ft_strdup(tokens[i + j]);
		j++;
	}
	args[arg_count] = NULL;
	return (args);
}
