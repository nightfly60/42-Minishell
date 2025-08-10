/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:22:30 by edurance          #+#    #+#             */
/*   Updated: 2025/08/10 18:35:21 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_readline(char *prompt, t_minishell *shell)
{
	char	*line;
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	ft_printf("%s", prompt);
	get_startpos(&shell->line->st_row, &shell->line->st_col);
	while (1)
	{
		bytes = read(STDIN_FILENO, &shell->line->buffer[i], 1);
		if (shell->line->buffer[i] == '\n')
			break ;
		i++;
	}
	shell->line->buffer[i + 1] = '\0';
	line = ft_strdup(shell->line->buffer);
	get_endpos(shell);
	ft_add_history(line, &shell->history);
	return (line);
}
