/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:01:30 by edurance          #+#    #+#             */
/*   Updated: 2025/08/17 15:02:08 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int count_cmd_args(char **tokens, int i)
{
	int arg_count;

	arg_count = 0;
	while (tokens[i + arg_count] && !is_operator(tokens[i + arg_count]))
		arg_count++;
	return (arg_count);
}

char **ft_argdup(char **tokens, int arg_count, int i)
{
	char **args;
	int	j;

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
