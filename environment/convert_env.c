/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:23:14 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/22 13:33:24 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

static int	ft_envlen(t_env *env)
{
	t_env	*current;
	int		i;

	i = 0;
	current = env;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

char	**convert_env(t_env *env)
{
	char	**res;
	char	*line;
	t_env	*current;
	int		i;

	res = malloc(sizeof(char *) * (ft_envlen(env) + 1));
	if (!res)
		return (NULL);
	current = env;
	i = 0;
	while (current)
	{
		line = ft_strjoin(current->name, "=");
		res[i] = ft_strjoin(line, current->value);
		free(line);
		current = current->next;
		i++;
	}
	res[i] = NULL;
	return (res);
}
