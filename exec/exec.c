/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:32:32 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/21 16:35:12 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static void	redir_input(t_list *cmd_block, t_cmd_block *block, int pipes[2])
{
	if (block->in_fd == 0 && block->pipe_fd != -1)
	{
		if (dup2(block->pipe_fd, STDIN_FILENO) == -1)
			perror("dup2");
		return ;
	}
	if (block->in_fd < 0)
		exit(1);
	if (dup2(block->in_fd, STDIN_FILENO) == -1)
		perror("dup2");
}

static int	redir_output(t_list *cmd_block, t_cmd_block *block, int pipes[2])
{
	if (!cmd_block->next)
	{
		if (block->out_fd < 0)
			return (1);
		if (dup2(block->out_fd, STDOUT_FILENO) == -1)
			print_error("dup2", NULL, 1);
	}
	else
	{
		if (dup2(pipes[1], STDOUT_FILENO) == -1)
			print_error("dup2", NULL, 1);
	}
	return (0);
}

void close_all(int pipes[2], t_cmd_block *command)
{
	int in;
	int out;

	in = command->in_fd;
	out = command->out_fd;
	close(pipes[0]);
	close(pipes[1]);
	if (in != 0)
		close(in);
	if (out != 1)
		close(out);
	if (command->pipe_fd > 0)
		close(command->pipe_fd);
}

void	exec_line(t_minishell *shell)
{
	t_list		*cmd_block;
	t_cmd_block	*command;
	int			pipes[2];
	int			pid;

	cmd_block = (shell->cmd_block);
	while (cmd_block)
	{
		pipe(pipes);
		pid = fork();
		if (pid == 0)
		{
			redir_input(cmd_block, command, pipes);
			if (redir_output(cmd_block, command, pipes))
			{
				perror(((t_redir *)ft_lstlast(command->out)->content)->name);
				exit(1);
			}
			close_all(pipes, command);
			command = (t_cmd_block *)cmd_block->content;
		}
		cmd_block = cmd_block->next;
	}
}
