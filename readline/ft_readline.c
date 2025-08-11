/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:22:30 by edurance          #+#    #+#             */
/*   Updated: 2025/08/11 15:13:41 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ft_readline.h"

char	*ft_readline(char *prompt, t_minishell *shell)
{
	char	*line;
	int		i;
	char	c;

	i = 0;
	ft_printf("%s", prompt);
	while (1)
	{
		read(STDIN_FILENO, &shell->line->buffer[i], 1);
		c = shell->line->buffer[i];
		if (c < 32 && c != '\t' && c != '\n' && c != '\r')
			shell->line->buffer[i] = 0;
		if (!arrow(c, shell) && !backspace(c, shell) && !ctrl_v(c))
			write(STDOUT_FILENO, &shell->line->buffer[i], 1);
		// ft_printf("|%d|", c);
		if (c == '\n')
			break ;
		i++;
	}
	shell->line->buffer[i + 1] = 0;
	line = ft_strdup(shell->line->buffer);
	ft_add_history(line, &(shell->history));
	return (line);
}
