/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:24:57 by edurance          #+#    #+#             */
/*   Updated: 2025/08/10 13:32:41 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# include "../minishell.h"

# ifndef BUF_MAX
#  define BUF_MAX 4097
# endif

/*structures*/
typedef struct s_line
{
	char	*buf;
	int		st_col;
	int		st_row;
	int		end_col;
	int		end_row;
}			t_line;

/*fonctions*/
char	*ft_readline(char *prompt, t_list **history);
void	ft_add_history(char *line, t_list **history);
void	delete_char(char *buf, int index);
void	insert_char(char *buf, char c, int index);

#endif
