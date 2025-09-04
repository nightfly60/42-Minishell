/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:22:10 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 17:11:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*Savoir si je considere ma quote comme tel ou comme un char normal.*/
static void	which_quotes(char c, int *inside, int *dquotes, int *squotes)
{
	if (c == '\"' && ((*inside && !is_even(*dquotes)) || (!*inside
				&& is_even(*dquotes))))
	{
		(*dquotes)++;
		if (*inside)
			*inside = 0;
		else
			*inside = 1;
	}
	else if (c == '\'' && ((*inside && !is_even(*squotes)) || (!*inside
				&& is_even(*squotes))))
	{
		(*squotes)++;
		if (*inside)
			*inside = 0;
		else
			*inside = 1;
	}
}

/*Verifie que les quotes se ferment bien.*/
int	quotes_checker(char *line)
{
	int	i;
	int	inside;
	int	squotes;
	int	dquotes;

	i = 0;
	inside = 0;
	squotes = 0;
	dquotes = 0;
	while (line && line[i])
	{
		which_quotes(line[i], &inside, &dquotes, &squotes);
		i++;
	}
	if (!is_even(dquotes) || !is_even(squotes))
	{
		ft_putstr_fd(line, STDERR_FILENO);
		ft_putstr_fd(": syntax error\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}
