/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:12:31 by edurance          #+#    #+#             */
/*   Updated: 2025/09/06 18:46:51 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*handle directory si il existe ou non*/
int	handle_dir(char **cmd, t_minishell *shell)
{
	int	fd;

	if (!ft_strchr(cmd[0], '/'))
		return (0);
	if (!access(cmd[0], F_OK) && access(cmd[0], X_OK))
	{
		perror(cmd[0]);
		shell->exit_status = 126;
		return (1);
	}
	fd = open(cmd[0], __O_DIRECTORY);
	if (fd == -1)
	{
		perror(cmd[0]);
		shell->exit_status = 127;
		return (1);
	}
	else
	{
		ft_putstr_fd(cmd[0], STDERR_FILENO);
		ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
		shell->exit_status = 126;
		close(fd);
		return (1);
	}
	return (0);
}
