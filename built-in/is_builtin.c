/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:17:43 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/05 13:29:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

int	is_builtin(char **name, t_minishell *shell)
{
	if (!ft_strcmp(name[0], "echo"))
		return (ft_echo(name, shell));
	else if (!ft_strcmp(name[0], "cd"))
		return (ft_cd(name, shell));
	else if (!ft_strcmp(name[0], "pwd"))
		return (ft_pwd(shell));
	else if (!ft_strcmp(name[0], "export"))
		return (ft_export(name, shell));
	else if (!ft_strcmp(name[0], "unset"))
		return (ft_unset(name, shell));
	else if (!ft_strcmp(name[0], "env"))
		return (ft_env(shell));
	else if (!ft_strcmp(name[0], "exit"))
		return (ft_exit(name, shell));
	else if (!ft_strcmp(name[0], "alias"))
		return (ft_alias(name, shell));
	else if (!ft_strcmp(name[0], "unalias"))
		return (ft_unalias(name, shell));
	return (0);
}
