/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:24:57 by edurance          #+#    #+#             */
/*   Updated: 2025/08/11 16:28:11 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# include "../minishell.h"

# ifndef BUF_MAX
#  define BUF_MAX 4097
# endif

typedef struct s_minishell	t_minishell;
/*structures*/
typedef struct s_line
{
	char	buffer[BUF_MAX];
	char	*new_line;
	int		st_col;
	int		st_row;
	int		end_col;
	int		end_row;
	int		index_hist;
}			t_line;

/*fonctions*/
char	*ft_readline(char *prompt, t_minishell *shell);
void	ft_add_history(char *line, t_list **history);
void	delete_char(char *buf, int index);
void	insert_char(char *buf, char c, int index);
void	switch_terminal(void);
void	get_cursorpos(int *row, int *col);
void	get_endpos(t_minishell *shell);
void	get_ttysize(t_minishell *shell);
void	clear_line(t_minishell *shell);
void	adapt_ttysize(t_minishell *shell);

/*	keys	*/
int			arrow(char c, t_minishell *shell);
int			backspace(char c, t_minishell *shell);
int			ctrl_v(char c);

#endif
