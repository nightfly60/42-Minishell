/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:33:30 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/19 12:40:08 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*Affiche les parse errors. Et voila !*/
int	parse_errors(t_minishell *shell)
{
	if (!quotes_checker((shell->line)) || check_operators(shell->tokens))
	{
		free_line(shell);
		return (1);
	}
	return (0);
}
