/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:50:42 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 12:14:10 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

static int	verify_flag(char *cmd)
{
	int	i;

	i = 2;
	while (cmd[i])
	{
		if (cmd[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	good_flag(int *i, char **cmd)
{
	int	flag;

	flag = 0;
	while (cmd[*i] && !ft_strncmp(cmd[*i], "-n", 2))
	{
		if (!verify_flag(cmd[*i]))
			return (flag);
		(*i)++;
		flag++;
	}
	return (flag);
}

int	ft_echo(char **cmd, t_minishell *shell)
{
	int	i;
	int	n_flag;

	i = 1;
	if (good_flag(&i, cmd))
		n_flag = 1;
	else
		n_flag = 0;
	while (cmd[i])
	{
		ft_printf("%s", cmd[i]);
		i++;
		if (cmd[i])
			ft_printf(" ");
	}
	if (!n_flag)
		ft_printf("\n");
	shell->exit_status = 0;
	return (1);
}
