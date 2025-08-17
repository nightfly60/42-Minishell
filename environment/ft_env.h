/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:26:57 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/17 12:46:12 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

# include "../minishell.h"

typedef struct s_minishell	t_minishell;

/*	variables d'environnement	*/
typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
	struct s_env	*previous;
}					t_env;

t_env	*env_last(t_env *lst);
void	env_add_back(t_env **lst, t_env *new);
void	env_delone(t_env *elem, void (*del)(void *));
t_env	*new_env(char *name, char *value);
void	copy_env(t_minishell *shell, char **env);
void	print_env(t_minishell *shell);
void	clear_env(t_env *lst, void (*f)(void *));
t_env	*find_var(char *name, t_env **first);
int		is_valid_id(char *s);
t_env	*find_var_len(char *name, t_env **first, int name_len);

#endif