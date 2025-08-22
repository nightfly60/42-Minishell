/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:20:27 by edurance          #+#    #+#             */
/*   Updated: 2025/08/22 12:26:24 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

# include "../minishell.h"

typedef struct s_cmd_block	t_cmd_block;

int							exec_line(t_minishell *shell);
void						close_child(int pipes[2], t_list *cmd_block);
void						close_parent(int pipas[2], t_cmd_block *command);

#endif
