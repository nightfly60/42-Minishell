/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:16:07 by edurance          #+#    #+#             */
/*   Updated: 2025/09/06 14:08:48 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILT_IN_H
# define FT_BUILT_IN_H

# include "minishell.h"

typedef struct s_minishell	t_minishell;
typedef struct s_cmd_block	t_cmd_block;

/*utils*/
typedef struct s_alias
{
	char					*name;
	char					*content;
	struct s_alias			*next;
	struct s_alias			*previous;
}							t_alias;

void	ft_print_alias(t_alias *alias_list);
int		modify_alias(t_alias *alias_list, char *name, char *content);
void	ft_add_alias(char *name, char *content, t_alias **alias_list);
int		find_alias(t_alias *alias_list, char *name);
void	clear_alias(t_alias *lst, void (*f)(void *));
int		is_builtin(t_cmd_block *command, t_minishell *shell, int is_pipe);
void	print_error(char *s1, char *s2, char *s3);
int		print_export_env(t_minishell *shell);

/*	redir builtin	*/
int		builtin_outfile(t_cmd_block *command, int is_pipe);
void	reset_output(int is_pipe, int saved);

/*built in*/
int		ft_alias(t_cmd_block *cmd, t_minishell *shell, int is_pipe);
int		ft_unset(t_cmd_block *cmd, t_minishell *shell, int is_pipe);
int		ft_echo(t_cmd_block *cmd, t_minishell *shell, int is_pipe);
int		ft_cd(t_cmd_block *cmd, t_minishell *shell, int is_pipe);
int		ft_pwd(t_cmd_block *cmd, t_minishell *shell, int is_pipe);
int		ft_unalias(t_cmd_block *cmd, t_minishell *shell, int is_pipe);
int		ft_env(t_cmd_block *cmd, t_minishell *shell, int is_pipe);
int		ft_exit(t_cmd_block *cmd, t_minishell *shell, int is_pipe);
int		ft_export(t_cmd_block *cmd, t_minishell *shell, int is_pipe);

#endif