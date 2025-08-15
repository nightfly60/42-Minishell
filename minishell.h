/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:51:44 by edurance          #+#    #+#             */
/*   Updated: 2025/08/15 16:53:18 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "built-in/ft_built_in.h"
# include "environment/ft_env.h"
# include "libft/libft.h"
# include "parsing/parsing.h"
# include <curses.h>
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
# include <term.h>
# include <termcap.h>
# include <termios.h>

typedef struct s_env	t_env;
typedef struct s_alias	t_alias;
/*struct minishell*/
typedef struct s_minishell
{
	char	*prompt;
	char	*line;
	char	**tokens;
	t_alias	*alias;
	t_env	*env;
}				t_minishell;

#endif
