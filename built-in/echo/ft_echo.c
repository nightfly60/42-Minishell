/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:50:42 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 10:58:11 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

int ft_echo(char **cmd, t_minishell *shell)
{
	int	i;
	int	n_flag;

	i = 1;
	if (cmd[i] && !ft_strcmp(cmd[i], "-n"))
	{
		i++;
		n_flag = 1;
	}
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
