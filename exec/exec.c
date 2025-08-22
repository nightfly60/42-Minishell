/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:32:32 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/22 12:30:35 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*	Execute une commande dans le fils fork.	*/
static void	child_process(t_cmd_block *command, int pipes[2], t_list *cmd_block)
{
	redir_input(command);
	if (redir_output(cmd_block, command, pipes))
	{
		perror(((t_redir *)ft_lstlast(command->out)->content)->name);
		exit(1);
	}
	close_child(pipes, cmd_block);
	execve(command->cmds[0], command->cmds, NULL);
}

/*	Execute les commande de la ligne.	*/
int	exec_line(t_minishell *shell)
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
		command = (t_cmd_block *)cmd_block->content;
		if (pid == 0)
			child_process(command, pipes, cmd_block);
		close_parent(pipes, command);
		cmd_block = cmd_block->next;
		if (cmd_block)
			((t_cmd_block *)cmd_block->content)->pipe_fd = pipes[0];
		else
			close(pipes[0]);
	}
	return (pid);
}
