/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:36:49 by edurance          #+#    #+#             */
/*   Updated: 2025/08/20 15:39:42 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

void apply_redirections(void *cmd_block)
{
	t_cmd_block *block;

	block = (t_cmd_block *)cmd_block;
	ft_lstiter(block->in, &redirect_input);
	ft_lstiter(block->out, &redirect_output);
}
