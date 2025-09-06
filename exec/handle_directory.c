/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:12:31 by edurance          #+#    #+#             */
/*   Updated: 2025/09/06 12:08:28 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*handle directory si il existe ou non*/
int	handle_dir(char **cmd, t_minishell *shell)
{
	int	fd;

	if (!ft_strchr(cmd[0], '/') || !ft_strncmp(cmd[0], "./", 2))
		return (0);
	fd = open(cmd[0], __O_DIRECTORY);
	if (fd == -1 && cmd[0][0] != '/')
	{
		perror(cmd[0]);
		shell->exit_status = 127;
		return (1);
	}
	else if (cmd[0][0] != '/')
	{
		ft_putstr_fd(cmd[0], STDERR_FILENO);
		ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
		shell->exit_status = 126;
		close(fd);
		return (1);
	}
	return (0);
}
