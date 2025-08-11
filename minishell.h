/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:51:44 by edurance          #+#    #+#             */
/*   Updated: 2025/08/11 16:25:47 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "libft/libft.h"
# include "readline/ft_readline.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

typedef struct s_line	t_line;

typedef struct s_ttysize
{
	int	row;
	int	col;
}			t_ttysize;

typedef struct s_line	t_line;

/*struct minishell*/
typedef struct s_minishell
{
	t_list		*history;
	t_line		*line;
	char		*prompt;
	t_ttysize	*size;
}				t_minishell;

#endif
