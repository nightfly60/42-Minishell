/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:51:48 by edurance          #+#    #+#             */
/*   Updated: 2025/08/09 19:05:23 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	switch_tty_mod(void)
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
	if (tcgetattr(STDIN_FILENO, &new) == -1 || tcgetattr(STDIN_FILENO, &old) ==
		-1)
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

int	arrow(char c)
{
	static int	index = 0;
	char		*sequence;

	sequence = "\x1b[";
	if (sequence[index] == c)
		index++;
	else
		index = 0;
	if (!sequence[index])
	{
		if (c == 'A')
			return (1);
		else if (c == 'B')
			return (1);
		else if (c == 'C')
		{
			write(STDOUT_FILENO, "\x1b[1C", 4);
			return (1);
		}
		else if (c == 'D')
		{
			write(STDOUT_FILENO, "\x1b[1D", 4);
			return (1);
		}
		index = 0;
		return (0);
	}
	return (0);
}

void	readprint(void)
{
	char	buff;

	ft_printf("> ");
	while (1)
	{
		read(STDIN_FILENO, &buff, 1);
		if (!arrow(buff))
			write(STDOUT_FILENO, &buff, 1);
	}
}

int	main(void)
{
	switch_tty_mod();
	readprint();
	switch_tty_mod();
}
