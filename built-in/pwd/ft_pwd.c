/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:43:45 by edurance          #+#    #+#             */
/*   Updated: 2025/09/06 19:05:07 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

/*built in pwd*/
int	ft_pwd(t_cmd_block *cmd, t_minishell *shell, int is_pipe)
{
	int	oldfd;

	oldfd = builtin_outfile(cmd, is_pipe);
	ft_printf("%s\n", shell->pwd);
	shell->exit_status = 0;
	reset_output(is_pipe, oldfd);
	return (1);
}
