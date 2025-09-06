/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:12:31 by edurance          #+#    #+#             */
/*   Updated: 2025/09/06 19:05:16 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static int	handle_dot(char **cmd, t_minishell *shell)
{
	if (ft_strcmp(cmd[0], ".") == 0)
	{
		ft_putstr_fd(".: filename argument required\n", STDERR_FILENO);
		ft_putstr_fd(".: usage: . filename [arguments]\n", STDERR_FILENO);
		shell->exit_status = 2;
		return (1);
	}
	return (0);
}

static int	handle_path(char **cmd, t_minishell *shell, int fd)
{
	if (ft_strchr(cmd[0], '/'))
	{
		if (fd != -1)
		{
			ft_putstr_fd(cmd[0], STDERR_FILENO);
			ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
			shell->exit_status = 126;
			close(fd);
			return (1);
		}
		if (access(cmd[0], F_OK) == -1)
		{
			perror(cmd[0]);
			shell->exit_status = 127;
			return (1);
		}
		if (access(cmd[0], X_OK) == -1)
		{
			perror(cmd[0]);
			shell->exit_status = 126;
			return (1);
		}
	}
	return (0);
}

/*handle directory si il existe ou non*/
int	handle_dir(char **cmd, t_minishell *shell)
{
	int	fd;

	if (!cmd[0])
		return (0);
	if (handle_dot(cmd, shell))
		return (1);
	fd = open(cmd[0], __O_DIRECTORY);
	if (handle_path(cmd, shell, fd))
		return (1);
	return (0);
}
