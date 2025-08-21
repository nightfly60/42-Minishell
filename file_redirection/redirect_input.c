/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:26:02 by edurance          #+#    #+#             */
/*   Updated: 2025/08/20 17:34:16 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

// void redirect_input(void *content, t_minishell *shell)
// {
//     int old_fd;
//     t_redir *in;

//     in = (t_redir *)content;
//     ft_printf("redirect_input: name=%s, type=%d\n", in->name, in->type);
//     if (in->type == INFILE)
//     {
//         old_fd = open_files(in->name, in->type);
//     }
//     else
//         old_fd = ft_heredoc(in->name);
//     // if (dup2(old_fd, STDIN_FILENO) == -1)
//     //     perror("dup2");
// 	if (!)
//     // close(old_fd);
// }
