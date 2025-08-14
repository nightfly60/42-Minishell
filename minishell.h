/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:51:44 by edurance          #+#    #+#             */
/*   Updated: 2025/08/14 16:27:41 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "libft/libft.h"
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
/*struct minishell*/
typedef struct s_minishell
{
}		t_minishell;

int		count_tokens(char *s);
char	*next_tokens(char *s);
char	**get_tokens(char *line);

#endif
