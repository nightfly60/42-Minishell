/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:32:32 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/06 13:21:57 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	display_cmd_not_found(char *string)
{
	if ((errno == ENOENT || !ft_strcmp(string, " ")) && !ft_strchr(string, '/'))
	{
		write(2, string, ft_strlen(string));
		write(2, ": command not found\n", 21);
		return ;
	}
	perror(string);
}

static void	exec_child(t_minishell *shell, t_cmd_block *command)
{
	char	**env;
	char	*command_path;

	command_path = get_path(command->cmds[0], shell);
	env = convert_env(shell->env);
	if (command_path && command->cmds[0][0])
		execve(command_path, command->cmds, env);
	if (command_path && command->cmds[0][0])
		display_cmd_not_found(command->cmds[0]);
	else if (command->cmds[0][0])
	{
		ft_putstr_fd(command->cmds[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	if (command->cmds[0][0])
		shell->exit_status = 1;
	else
		shell->exit_status = 0;
	if (errno == ENOENT || !command_path)
		shell->exit_status = 127;
	free(command_path);
	ft_freeall(env);
	exit_minishell(shell);
}

/*	Execute une commande dans le fils fork.	*/
static void	child_process(t_cmd_block *command, int pipes[2], t_list *cmd_block,
		t_minishell *shell)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (redir_input(command))
	{
		if (pipes[0] > 2)
			close(pipes[0]);
		if (pipes[1] > 2)
			close(pipes[1]);
		exit_minishell(shell);
	}
	if (redir_output(cmd_block, command, pipes))
	{
		if (pipes[0] > 2)
			close(pipes[0]);
		if (pipes[1] > 2)
			close(pipes[1]);
		exit_minishell(shell);
	}
	close_child(pipes, cmd_block);
	if (command->is_valid && (is_builtin(command, shell, 1)
			|| handle_dir(command->cmds, shell)))
		exit_minishell(shell);
	exec_child(shell, command);
}

/*	Execute les commande de la ligne.	*/
int	exec_line(t_minishell *shell)
{
	t_list		*cmd_block;
	t_cmd_block	*command;
	int			pipes[2];
	int			pid;

	cmd_block = (shell->cmd_block);
	command = (t_cmd_block *)cmd_block->content;
	if (command->is_valid && !cmd_block->next && is_builtin(command, shell, 0))
		return (-1);
	while (cmd_block)
	{
		pipe(pipes);
		pid = fork();
		command = (t_cmd_block *)cmd_block->content;
		if (pid == 0)
			child_process(command, pipes, cmd_block, shell);
		close_parent(pipes, command);
		cmd_block = cmd_block->next;
		if (cmd_block)
			((t_cmd_block *)cmd_block->content)->pipe_fd = pipes[0];
		else
			close(pipes[0]);
	}
	return (pid);
}
