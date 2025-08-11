/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_terminal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:10:15 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/11 16:12:21 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

/*Passer du mode canonique au non-canonique et inversement.*/
void	switch_terminal(void)
{
	static int				status = 0;
	static struct termios	old;
	static struct termios	new;

	if (status)
	{
		if (tcsetattr(STDIN_FILENO, TCSANOW, &old) == -1)
			perror("tcsetattr: ");
		status = 0;
		return ;
	}
	if (tcgetattr(STDIN_FILENO, &new) == -1
		|| tcgetattr(STDIN_FILENO, &old) == -1)
	{
		perror("tcgetattr: ");
		return ;
	}
	new.c_lflag = new.c_lflag & ~ICANON;
	new.c_lflag = new.c_lflag & ~ECHO;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &new) == -1)
		perror("tcsetattr: ");
	status = 1;
}
