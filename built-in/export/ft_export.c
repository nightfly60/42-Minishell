/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:05:23 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/06 14:15:56 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

static void	export_var(char *str, t_minishell *shell)
{
	char	**split;

	if (str[0] == '=')
	{
		print_error("export: `", str, "': not a valid identifier\n");
		shell->exit_status = 1;
		return ;
	}
	split = ft_split(str, '=');
	if (is_valid_id(split[0]) != (int)ft_strlen(split[0]))
	{
		shell->exit_status = 1;
		print_error("export: `", split[0], "': not a valid identifier\n");
		ft_freeall(split);
		return ;
	}
	if (ft_strchr(str, '=') && !split[1])
		modify_env(split[0], "", &shell->env);
	else
		modify_env(split[0], split[1], &shell->env);
	ft_freeall(split);
}

int	ft_export(t_cmd_block *cmd, t_minishell *shell, int is_pipe)
{
	int		i;
	char	**cmds;
	int		oldfd;

	oldfd = builtin_outfile(cmd, is_pipe);
	cmds = cmd->cmds;
	shell->exit_status = 0;
	if (!cmds[1])
	{
		reset_output(is_pipe, oldfd);
		return (print_export_env(shell));
	}
	i = 1;
	while (cmds[i])
	{
		export_var(cmds[i], shell);
		i++;
	}
	reset_output(is_pipe, oldfd);
	return (1);
}
