/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:25:20 by edurance          #+#    #+#             */
/*   Updated: 2025/08/20 18:12:51 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

void	ft_expand_heredoc(char **tokens, t_env *env)
{
	int	i;

	i = 0;
	if (tokens[i][0] == '"')
		double_quote(&tokens[i], env);
	else if (tokens[i][0] == '\'')
		single_quote(&tokens[i]);
	else
		ft_word_expansion(&tokens[i], env);
	i++;
}

int	ft_heredoc(char *limiter, t_minishell *shell, t_redirtype type)
{
	char	*line;
	char	*text;
	int		len;
	int		fd[2];

	line = NULL;
	text = NULL;
	len = ft_strlen(limiter);
	if (pipe(fd) == -1)
		perror("pipe");
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (type == HEREDOC)
			ft_expand_heredoc(&line, shell->env);
		if (!line || (!ft_strncmp(limiter, line, len) && line[len] == '\n'))
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	get_next_line(-1);
	close(fd[1]);
	return (fd[0]);
}
