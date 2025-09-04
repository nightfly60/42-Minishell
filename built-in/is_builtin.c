/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:17:43 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/03 16:59:06 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

int	is_builtin(char **name, t_minishell *shell)
{
	if (!ft_strcmp(name[0], "echo"))
		return (1);
	else if (!ft_strcmp(name[0], "cd"))
		return (1);
	else if (!ft_strcmp(name[0], "pwd"))
		return (1);
	else if (!ft_strcmp(name[0], "export"))
		return (1);
	else if (!ft_strcmp(name[0], "unset"))
		return (ft_unset(name, shell));
	else if (!ft_strcmp(name[0], "env"))
		return (1);
	else if (!ft_strcmp(name[0], "exit"))
		return (1);
	else if (!ft_strcmp(name[0], "alias"))
		return (1);
	return (0);
}
