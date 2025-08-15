/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:22:39 by edurance          #+#    #+#             */
/*   Updated: 2025/08/15 15:45:57 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minishell.h"

/*structs*/
typedef struct s_alias	t_alias;

/*	parsing prototypes	*/
int						is_even(int n);
int						quotes_checker(char *line);

/*	tokenize	*/
int						is_operator(char *s);
int						is_quote(char *s);
int						count_tokens(char *s);
char					**get_tokens(char *line);
char					**ft_merge_tokens(char *line, char **tokens);
void	free_str_array(char **arr);

/*	expensions	*/
void					ft_alias_expansion(char **args, t_alias *alias);

#endif