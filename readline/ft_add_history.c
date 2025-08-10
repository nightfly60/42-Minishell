/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:27:27 by edurance          #+#    #+#             */
/*   Updated: 2025/08/10 18:38:43 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	ft_add_history(char *line, t_list **history)
{
	t_list	*new_line;
	char	*line_copy;

	if (!line[0] || line[0] == '\n')
		return ;
	new_line = malloc(sizeof(t_list));
	if (!new_line)
		return ;
	line_copy = ft_strdup(line);
	new_line->content = line_copy;
	new_line->next = NULL;
	ft_lstadd_front(history, new_line);
}
