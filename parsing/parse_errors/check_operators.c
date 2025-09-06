/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:20:41 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/06 22:50:11 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	print_operator_err(char *token)
{
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	return (1);
}

/*Savoir si je considere ma operator comme tel ou comme un char normal.*/
int	check_operators(char **tokens)
{
	int	i;

	i = 0;
	while (tokens && tokens[i])
	{
		if (is_operator(tokens[i]))
		{
			if (!tokens[i + 1])
				return (print_operator_err("newline"));
			else if (!ft_strcmp("|", tokens[i]) && !ft_strcmp("|", tokens[i
						+ 1]))
			{
				return (print_operator_err(tokens[i + 1]));
			}
		}
		i++;
	}
	return (0);
}
