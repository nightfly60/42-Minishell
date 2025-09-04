/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:16:07 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 10:55:03 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILT_IN_H
# define FT_BUILT_IN_H

# include "../minishell.h"

typedef struct s_minishell	t_minishell;

/*alias*/
typedef struct s_alias
{
	char					*name;
	char					*content;
	struct s_alias			*next;
	struct s_alias			*previous;
}							t_alias;

int							ft_alias(char **args, t_alias **alias_list);
void						ft_print_alias(t_alias *alias_list);
int							modify_alias(t_alias *alias_list, char *name,
								char *content);
void						ft_add_alias(char *name, char *content,
								t_alias **alias_list);
int							find_alias(t_alias *alias_list, char *name);
void						ft_unalias(char *del_name, t_alias **alias);
void						clear_alias(t_alias *lst, void (*f)(void *));
int							is_builtin(char **name, t_minishell *shell);
int							ft_unset(char **cmd, t_minishell *shell);
int							ft_echo(char **cmd, t_minishell *shell);

#endif