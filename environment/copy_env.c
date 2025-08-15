/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:36:41 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/15 17:07:34 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

static char	*get_var_name(char *s)
{
	char	*res;
	int		i;

	i = 0;
	res = strdup(s);
	while (res[i])
	{
		if (res[i] == '=')
		{
			res[i] = 0;
			break ;
		}
		i++;
	}
	return (res);
}

void	copy_env(t_minishell *shell, char **env)
{
	int		i;
	char	*name;
	t_env	*new;

	i = 0;
	while (env[i])
	{
		name = get_var_name(env[i]);
		if (getenv(name))
		{
			if (ft_strncmp(name, "SHLVL", 5))
				new = new_env(name, getenv(name));
			else
				new = new_env(name, ft_itoa(ft_atoi(getenv(name)) + 1));
			env_add_back(&(shell->env), new);
		}
		free(name);
		i++;
	}
}
