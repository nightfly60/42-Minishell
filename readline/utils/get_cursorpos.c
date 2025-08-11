/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursorpos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:31:21 by edurance          #+#    #+#             */
/*   Updated: 2025/08/11 14:47:39 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

/*Lit une donnee de type /033[42;64R et place les infos dans row et col.*/
static void	parse_position(char *buf, int *row, int *col)
{
	int	i;

	i = 0;
	*row = (int)ft_atoi(&buf[i]);
	while (buf[i - 1] != ';')
		i++;
	*col = (int)ft_atoi(&buf[i]);
}

/*Trouve la position actuelle du curseur (en envoyant en sequence au terminal et read).*/
void	get_cursorpos(int *row, int *col)
{
	char	buf[32];
	int		i;
	char	c;

	i = 0;
	switch_terminal();
	write(STDOUT_FILENO, "\033[6n", 4);
	while (i < 32 - 1)
	{
		if (read(STDIN_FILENO, &c, 1) <= 0)
			break ;
		buf[i++] = c;
		if (c == 'R')
			break ;
	}
	buf[i] = '\0';
	switch_terminal();
	if (buf[0] == '\033' && buf[1] == '[')
		parse_position(buf + 2, row, col);
	else
	{
		*row = -1;
		*col = -1;
	}
}
