/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:32:32 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/04 10:51:03 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

void	print_error(char *string)
{
	if ((errno == ENOENT || !ft_strcmp(string, " ")) && !ft_strchr(string, '/'))
	{
		write(2, string, ft_strlen(string));
		write(2, ": command not found\n", 21);
		return ;
	}
	perror(string);
}

/*	Execute une commande dans le fils fork.	*/
static void	child_process(t_cmd_block *command, int pipes[2], t_list *cmd_block,
		t_minishell *shell)
{
	char	*command_path;
	char	**env;

	signal(SIGINT, SIG_DFL);
	redir_input(command);
	if (redir_output(cmd_block, command, pipes))
	{
		perror(((t_redir *)ft_lstlast(command->out)->content)->name);
		exit(1);
	}
	close_child(pipes, cmd_block);
	if (is_builtin(command->cmds, shell))
		exit_minishell(shell);
	command_path = get_path(command->cmds[0], shell);
	env = convert_env(shell->env);
	if (command_path && command->cmds[0][0])
		execve(command_path, command->cmds, env);
	if (command_path && command->cmds[0][0])
		print_error(command->cmds[0]);
	else if (command->cmds[0][0])
	{
		ft_putstr_fd(command->cmds[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	shell->exit_status = 0;
	if (errno == ENOENT || !command_path)
		shell->exit_status = 127;
	free(command_path);
	ft_freeall(env);
	exit_minishell(shell);
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
	if (!cmd_block->next && is_builtin(command->cmds, shell))
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
