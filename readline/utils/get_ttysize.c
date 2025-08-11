/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ttysize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:14:23 by edurance          #+#    #+#             */
/*   Updated: 2025/08/11 16:14:32 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

void	get_ttysize(t_minishell *shell)
{
	struct winsize	w;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0)
	{
		if (shell->size == NULL)
		{
			shell->size = malloc(sizeof(t_ttysize));
			if (!shell->size)
				return ;
		}
		shell->size->col = w.ws_col;
		shell->size->row = w.ws_row;
	}
}
