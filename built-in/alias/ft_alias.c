/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:15:36 by edurance          #+#    #+#             */
/*   Updated: 2025/08/14 17:35:24 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

static int	check_eq(char *args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (args[i] == '=')
		{
			j = 1;
			i++;
			break ;
		}
		i++;
	}
	if (i == j)
		return (0);
	return (1);
}

static int	handle_alias(t_alias **alias_list, char *args)
{
	char	*name;
	char	*content;
	char	*eq;

	if (!ft_strchr(args, '=') || !check_eq(args))
	{
		if (!find_alias(*alias_list, args))
		{
			ft_printf("minishell: alias: %s: not found\n", args);
			return (0);
		}
	}
	else
	{
		eq = ft_strchr(args, '=');
		*eq = '\0';
		name = args;
		content = eq + 1;
		ft_add_alias(name, content, alias_list);
	}
	return (1);
}

int	ft_alias(char **args, t_alias **alias_list)
{
	int		i;
	int		arg_count;

	i = 0;
	arg_count = ft_arrlen(args);
	if (arg_count == 1)
	{
		ft_print_alias(*alias_list);
		return (0);
	}
	else if (arg_count == 2)
	{
		if (!handle_alias(alias_list, args[1]))
			return (0);
	}
	return (1);
}
