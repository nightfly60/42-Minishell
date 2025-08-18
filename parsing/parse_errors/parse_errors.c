/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:33:30 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/18 15:34:46 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	parse_errors(t_minishell *shell)
{
	if (!quotes_checker((shell->line)) || check_operators(shell->tokens))
	{
		free_line(shell);
		return (1);
	}
	return (0);
}
