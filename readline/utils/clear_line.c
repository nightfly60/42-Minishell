/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:13:16 by edurance          #+#    #+#             */
/*   Updated: 2025/08/11 16:13:48 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

void	clear_line(t_minishell *shell)
{
	ft_printf("\033[%d;%dH", shell->line->st_row, shell->line->st_col);
	ft_printf("\033[J");
	ft_printf("\33[2K\r");
}
