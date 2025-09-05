/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:14:36 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/05 13:25:27 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

static void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	print_export_env(t_minishell *shell)
{
	char	**env;
	int		i;

	i = 0;
	env = convert_env(shell->env);
	while (env[i + 1])
	{
		if (strcmp(env[i], env[i + 1]) > 0)
		{
			ft_swap(&env[i], &env[i + 1]);
			i = -1;
		}
		i++;
	}
	i = 0;
	while (env[i])
	{
		ft_printf("%s", env[i]);
		if (env[i][ft_strlen(env[i]) - 1] == '=')
			write(STDOUT_FILENO, "''", 2);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	ft_freeall(env);
	return (1);
}
