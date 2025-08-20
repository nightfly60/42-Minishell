/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:51:44 by edurance          #+#    #+#             */
/*   Updated: 2025/08/20 15:46:03 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*includes*/
# include "built-in/ft_built_in.h"
# include "environment/ft_env.h"
# include "libft/libft.h"
# include "parsing/parsing.h"
# include "file_redirection/ft_redirection.h"
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

typedef enum e_redirtype
{
	INFILE,
	OUTFILE,
	HEREDOC,
	HEREDOC_NO_EXP,
	APPEND
}						t_redirtype;

typedef struct s_redir
{
	char				*name;
	t_redirtype			type;
}						t_redir;

typedef struct s_cmd_block
{
	t_list				*in;
	t_list				*out;
	char				**cmds;
}						t_cmd_block;

typedef struct s_env	t_env;
typedef struct s_alias	t_alias;
/*struct minishell*/
typedef struct s_minishell
{
	char				*prompt;
	char				*line;
	char				**tokens;
	t_list				*cmd_block;
	t_alias				*alias;
	t_env				*env;
}						t_minishell;

/*DEBUG*/
void					print_cmd(void *commands);

/*	utils Minishell	*/
void					free_line(t_minishell *shell);
void					init_shell(t_minishell *shell, char **env);
void					exit_minishell(t_minishell *shell);

#endif
