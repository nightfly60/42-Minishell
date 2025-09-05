/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:05:23 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/05 13:24:27 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

static void	export_var(char *str, t_minishell *shell)
{
	char	**split;

	if (str[0] == '=')
	{
		print_error("export: `", str, "': not a valide identifier\n");
		return ;
	}
	split = ft_split(str, '=');
	if (!is_valid_id(split[0]))
	{
		print_error("export: `", split[0], "': not a valide identifier\n");
		ft_freeall(split);
		return ;
	}
	if (ft_strchr(str, '=') && !split[1])
		modify_env(split[0], "", &shell->env);
	else
		modify_env(split[0], split[1], &shell->env);
	ft_freeall(split);
}

int	ft_export(char **cmds, t_minishell *shell)
{
	int	i;

	if (!cmds[1])
		return (print_export_env(shell));
	i = 1;
	while (cmds[i])
	{
		export_var(cmds[i], shell);
		i++;
	}
	return (1);
}
