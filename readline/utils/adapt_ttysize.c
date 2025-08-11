/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_ttysize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:15:05 by edurance          #+#    #+#             */
/*   Updated: 2025/08/11 16:15:13 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

void	adapt_ttysize(t_minishell *shell)
{
	struct winsize w;
	int x,y;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) != 0)
		return ;
	if (shell->size->col != w.ws_col || shell->size->row != w.ws_row)
	{
		//ft_printf("[DEBUG]");
		get_ttysize(shell);
		get_cursorpos(&x, &y);
		clear_line(shell);
		ft_printf("%s%s", shell->prompt, shell->line->buffer);
		get_endpos(shell);
	}
}
