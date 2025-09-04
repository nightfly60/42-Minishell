/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:23:03 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/04 11:17:26 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

static int	is_str_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	print_error(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, STDERR_FILENO);
	ft_putstr_fd(s2, STDERR_FILENO);
	ft_putstr_fd(s3, STDERR_FILENO);
}

static long long	ft_atoll(const char *nptr)
{
	int			i;
	int			signe;
	long long	res;

	i = 0;
	res = 0;
	signe = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		signe = signe * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * signe);
}

int	ft_exit(char **cmds, t_minishell *shell)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (!cmds[1])
		exit_minishell(shell);
	if (!is_str_num(cmds[1]) || ft_strlen(cmds[1]) > 20)
	{
		shell->exit_status = 2;
		print_error("exit: ", cmds[1], ": numeric argument required\n");
		exit_minishell(shell);
	}
	if (cmds[2])
	{
		shell->exit_status = 1;
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	shell->exit_status = ft_atoll(cmds[1]) % 256;
	exit_minishell(shell);
	return (1);
}
