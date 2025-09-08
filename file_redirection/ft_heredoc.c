/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:25:20 by edurance          #+#    #+#             */
/*   Updated: 2025/09/07 12:39:22 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

void	ft_expand_heredoc(char **tokens, t_env *env)
{
	int	i;

	i = 0;
	if (!tokens[i])
		return ;
	if (tokens[i][0] == '"')
		double_quote(&tokens[i], env);
	else if (tokens[i][0] == '\'')
		single_quote(&tokens[i]);
	else
		ft_word_expansion(&tokens[i], env);
	i++;
}

static int	here_doc_error(char *limiter, char *line, int actual_line)
{
	int		len;
	char	*itoa_line;

	len = ft_strlen(limiter);
	if (!line || (!ft_strncmp(limiter, line, len) && line[len] == '\n'))
	{
		if (!line)
		{
			itoa_line = ft_itoa(actual_line);
			ft_putstr_fd("\nwarning: here-document at line ", STDERR_FILENO);
			ft_putstr_fd(itoa_line, STDERR_FILENO);
			ft_putstr_fd(" delimited by end-of-file (wanted `", STDERR_FILENO);
			ft_putstr_fd(limiter, STDERR_FILENO);
			ft_putstr_fd("')\n", STDERR_FILENO);
			free(itoa_line);
		}
		return (1);
	}
	return (0);
}

void	open_heredoc(int fd[2], t_redirtype type, t_minishell *shell,
		char *limiter)
{
	int		count_line;
	char	*line;

	signal(SIGINT, gest_sigint);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("dup2");
	close(fd[1]);
	close(fd[0]);
	count_line = 0;
	line = NULL;
	while (1)
	{
		write(2, "> ", 2);
		count_line++;
		line = get_next_line(STDIN_FILENO);
		if (type == HEREDOC)
			ft_expand_heredoc(&line, shell->env);
		if (here_doc_error(limiter, line, count_line))
			break ;
		write(STDOUT_FILENO, line, ft_strlen(line));
		free(line);
	}
	free(line);
	get_next_line(-1);
	exit_minishell(shell);
}

void	wait_heredoc(t_minishell *shell, int pid, t_cmd_block *block)
{
	int	status;

	if (pid < 0)
		return ;
	status = 0;
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) != 130)
		shell->exit_status = WEXITSTATUS(status);
	else
	{
		block->is_valid = 0;
		shell->exit_status = 130;
		write(1, "\n", 1);
	}
}

int	ft_heredoc(char *limiter, t_minishell *shell, t_redirtype type,
		t_cmd_block *block)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		perror("pipe");
	pid = ft_fork();
	if (pid == 0)
		open_heredoc(fd, type, shell, limiter);
	wait_heredoc(shell, pid, block);
	close(fd[1]);
	return (fd[0]);
}
