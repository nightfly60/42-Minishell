/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:40:23 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/06 14:13:05 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

/*	buil-in : env	*/
int	ft_env(t_cmd_block *cmd, t_minishell *shell, int is_pipe)
{
	int	oldfd;

	oldfd = builtin_outfile(cmd, is_pipe);
	print_env(shell);
	shell->exit_status = 0;
	reset_output(is_pipe, oldfd);
	return (1);
}
