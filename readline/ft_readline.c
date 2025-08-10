/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:22:30 by edurance          #+#    #+#             */
/*   Updated: 2025/08/10 13:32:52 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_readline(char *prompt, t_list **history)
{
	char	buffer[4097];
	char	*line;
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	ft_printf("%s", prompt);
	while (1)
	{
		bytes = read(STDIN_FILENO, &buffer[i], 1);
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	buffer[i + 1] = '\0';
	line = ft_strdup(buffer);
	ft_add_history(line, history);
	return (line);
}
