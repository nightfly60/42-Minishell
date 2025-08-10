/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_endpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:32:45 by edurance          #+#    #+#             */
/*   Updated: 2025/08/10 18:48:22 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

/*Modifie end_row et end_col pour y mettre la position de la fin de la ligne dans le terminal.*/
void	get_endpos(t_minishell *shell)
{
	int	total_offset;

	total_offset = shell->line->st_col + (int)ft_strlen(shell->line->buffer)
		- 1;
	shell->line->end_row = shell->line->st_row + (total_offset
			/ shell->size->col);
	shell->line->end_col = total_offset % shell->size->col;
}
