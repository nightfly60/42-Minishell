/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:20:41 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/18 15:39:50 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	check_operators(char **tokens)
{
	int	i;

	i = 0;
	while (tokens && tokens[i])
	{
		if (is_operator(tokens[i]))
		{
			if (!tokens[i + 1])
				return (ft_printf("syntax error near unexpected token `newline'\n"));
			else if (is_operator(tokens[i + 1]))
				return (ft_printf("syntax error near unexpected token `%s'\n",
						tokens[i + 1]));
		}
		i++;
	}
	return (0);
}
