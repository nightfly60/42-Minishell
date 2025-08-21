/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:38:19 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/20 18:13:38 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REDIRECTION_H
# define FT_REDIRECTION_H

# include "../minishell.h"

typedef enum e_redirtype	t_redirtype;

/*	fonction de redirection	*/
int							open_files(char *name, t_redirtype type);
int							ft_heredoc(char *limiter, t_minishell *shell,
								t_redirtype type);
void						set_finals_fd(t_minishell *shell);

#endif
