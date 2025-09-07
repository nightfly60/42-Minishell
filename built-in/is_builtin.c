/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:17:43 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/07 13:15:34 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

int	builtin_outfile(t_cmd_block *command, int is_pipe)
{
	int	saved;

	if (is_pipe)
		return (-1);
	saved = dup(STDOUT_FILENO);
	if (command->out_fd != STDOUT_FILENO)
	{
		if (command->out_fd < 0)
			return (saved);
		if (dup2(command->out_fd, STDOUT_FILENO) == -1)
			perror("dup2");
	}
	return (saved);
}

void	reset_output(int is_pipe, int saved)
{
	if (is_pipe)
		return ;
	if (dup2(saved, STDOUT_FILENO) == -1)
		perror("dup2");
	close(saved);
}

int	is_builtin(t_cmd_block *command, t_minishell *shell, int is_pipe)
{
	if (!command->cmds[0])
		return (0);
	if (!ft_strcmp(command->cmds[0], "echo"))
		return (ft_echo(command, shell, is_pipe));
	else if (!ft_strcmp(command->cmds[0], "cd"))
		return (ft_cd(command, shell, is_pipe));
	else if (!ft_strcmp(command->cmds[0], "pwd"))
		return (ft_pwd(command, shell, is_pipe));
	else if (!ft_strcmp(command->cmds[0], "export"))
		return (ft_export(command, shell, is_pipe));
	else if (!ft_strcmp(command->cmds[0], "unset"))
		return (ft_unset(command, shell, is_pipe));
	else if (!ft_strcmp(command->cmds[0], "env"))
		return (ft_env(command, shell, is_pipe));
	else if (!ft_strcmp(command->cmds[0], "exit"))
		return (ft_exit(command, shell, is_pipe));
	else if (!ft_strcmp(command->cmds[0], "alias"))
		return (ft_alias(command, shell, is_pipe));
	else if (!ft_strcmp(command->cmds[0], "unalias"))
		return (ft_unalias(command, shell, is_pipe));
	return (0);
}
