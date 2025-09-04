/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:12:31 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 15:17:43 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*handle directory si il existe ou non*/
int handle_directory(char **cmd, t_minishell *shell)
{
	int fd;

	fd = open(cmd[0], __O_DIRECTORY);
	if (fd == -1)
	{
		ft_printf("%s: No such file or directory\n", cmd[0]);
		shell->exit_status = 127;
		return (1);
	}
	else
	{
		ft_printf("%s: Is a directory\n", cmd[0]);
		shell->exit_status = 126;
		close(fd);
		return (1);
	}
	return (0);
}
