/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:51:48 by edurance          #+#    #+#             */
/*   Updated: 2025/08/09 17:51:47 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_content(void *content)
{
	printf("%s", (char *)content);
}

void	ft_add_history(char *line, t_list **history)
{
	t_list	*new_line;
	char	*line_copy;

	new_line = malloc(sizeof(t_list));
	if (!new_line)
		return ;
	line_copy = ft_strdup(line);
	new_line->content = line_copy;
	new_line->next = NULL;
	ft_lstadd_front(history, new_line);
}

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

int	main(void)
{
	t_list	*history;
	char	*line;

	history = NULL;
	line = ft_readline("Entre une premiere phrase : ", &history);
	ft_printf("La premiere phrase est : %s", line);
	free(line);
	line = ft_readline("Entre une deuxieme phrase : ", &history);
	ft_printf("La deuxieme phrase est : %s", line);
	free(line);
	line = ft_readline("Entre une troisieme phrase : ", &history);
	ft_printf("La troisieme phrase est : %s", line);
	free(line);
	ft_printf("\nVoici votre historique :\n");
	ft_lstiter(history, print_content);
	ft_lstclear(&history, free);
	return (0);
}
