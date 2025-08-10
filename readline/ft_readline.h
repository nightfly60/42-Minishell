/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:24:57 by edurance          #+#    #+#             */
/*   Updated: 2025/08/10 18:33:40 by edurance         ###   ########.fr       */
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
	char	c;
	int		st_col;
	int		st_row;
	int		end_col;
	int		end_row;
}			t_line;

/*fonctions*/
char	*ft_readline(char *prompt, t_minishell *shell);
void	ft_add_history(char *line, t_list **history);
void	delete_char(char *buf, int index);
void	insert_char(char *buf, char c, int index);
void	switch_terminal(void);
void	get_startpos(int *row, int *col);
void	get_endpos(t_minishell *shell);

#endif
