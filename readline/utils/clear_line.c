/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:13:16 by edurance          #+#    #+#             */
/*   Updated: 2025/08/11 16:53:08 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

void	clear_line(t_minishell *shell)
{
	ft_printf("%d et %d\n", shell->line->st_row, shell->line->st_col);
	int a,b;
	get_cursorpos(&a, &b);
	ft_printf("%d et %d\n", a, b);
	ft_printf("\033[%d;%dH", shell->line->st_row, shell->line->st_col);
	sleep(2);
	ft_printf("\033[J");
	sleep(2);
	ft_printf("\33[2K\r");
	sleep(2);
}
