/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:51:48 by edurance          #+#    #+#             */
/*   Updated: 2025/08/10 13:28:01 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_content(void *content)
{
	printf("%s", (char *)content);
}

int	main(void)
{
	char	buf[BUF_MAX] = "salut\n";

	// t_list	*history;
	// char	*line;
	// history = NULL;
	// line = ft_readline("Entre une premiere phrase : ", &history);
	// ft_printf("La premiere phrase est : %s", line);
	// free(line);
	// line = ft_readline("Entre une deuxieme phrase : ", &history);
	// ft_printf("La deuxieme phrase est : %s", line);
	// free(line);
	// line = ft_readline("Entre une troisieme phrase : ", &history);
	// ft_printf("La troisieme phrase est : %s", line);
	// free(line);
	// ft_printf("\nVoici votre historique :\n");
	// ft_lstiter(history, print_content);
	// ft_lstclear(&history, free);

	printf("buffer avant = %s", buf);
	insert_char(buf, 'X', 3);
	printf("buffer apres | avant delete = %s", buf);
	delete_char(buf, 3);
	printf("apres delete = %s", buf);
	return (0);
}
