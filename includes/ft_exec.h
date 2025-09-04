/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:20:27 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 17:17:39 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

# include "minishell.h"

typedef struct s_cmd_block	t_cmd_block;
typedef struct s_list		t_list;
typedef struct s_minishell	t_minishell;

int							exec_line(t_minishell *shell);
void						close_child(int pipes[2], t_list *cmd_block);
void						close_parent(int pipas[2], t_cmd_block *command);
char						*get_path(char *command, t_minishell *shell);
void						exit_wait(t_minishell *shell, int last);
int							handle_dir(char **cmd, t_minishell *shell);

#endif
