/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:22:39 by edurance          #+#    #+#             */
/*   Updated: 2025/08/19 12:05:24 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minishell.h"

/*structs*/
typedef struct s_alias		t_alias;
typedef struct s_cmd_block	t_cmd_block;
typedef struct s_env		t_env;
typedef struct s_minishell	t_minishell;

/*	parsing prototypes	*/
int							is_even(int n);
int							quotes_checker(char *line);
int							check_operators(char **tokens);
int							parse_errors(t_minishell *shell);

/*	tokenize	*/
int							is_operator(char *s);
int							is_quote(char *s);
int							count_tokens(char *s);
char						**get_tokens(char *line);
char						**ft_merge_tokens(char *line, char **tokens);
void						free_str_array(char **arr);


/*	commands (parse pipeline)	*/
int							count_cmd_args(char **tokens, int i);
char						**ft_argdup(char **tokens, int arg_count, int i);
void						parse_pipeline(t_minishell *shell);

/*	expensions	*/
void						ft_alias_expansion(char **args, t_alias *alias);
void						ft_expand_tokens(char **tokens, t_env *env);
void						ft_word_expansion(char **s, t_env *env);

#endif