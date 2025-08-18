/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:20:41 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/18 17:04:49 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

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
				return (ft_printf(
						"syntax error near unexpected token `newline'\n"));
			else if (is_operator(tokens[i + 1]))
				return (ft_printf("syntax error near unexpected token `%s'\n",
						tokens[i + 1]));
		}
		i++;
	}
	return (0);
}
