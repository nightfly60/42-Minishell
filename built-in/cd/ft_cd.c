/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:15:18 by edurance          #+#    #+#             */
/*   Updated: 2025/09/06 14:12:11 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

/*affiche la bonne erreur*/
static int	display_cd_error(char *name, int error, t_minishell *shell,
		int old_fd)
{
	if (old_fd > 0)
		reset_output(0, old_fd);
	if (error == 1)
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd("cd: HOME not set\n", STDERR_FILENO);
	else if (error == 3)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		perror(name);
	}
	shell->exit_status = 1;
	return (1);
}

static void	update_pwd(t_minishell *shell)
{
	t_env	*pwd;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	pwd = find_var("PWD", &shell->env);
	modify_env("OLDPWD", pwd->value, &shell->env);
	modify_env("PWD", cwd, &shell->env);
	free(cwd);
	free(shell->pwd);
	shell->pwd = getcwd(NULL, 0);
}

/*built in cd*/
int	ft_cd(t_cmd_block *cmd, t_minishell *shell, int is_pipe)
{
	char	**name;
	t_env	*home;
	int		oldfd;

	oldfd = builtin_outfile(cmd, is_pipe);
	name = cmd->cmds;
	shell->exit_status = 0;
	home = find_var("HOME", &shell->env);
	if ((!home || !home->value) && ft_arrlen(name) < 2)
		return (display_cd_error(name[1], 2, shell, oldfd));
	if (ft_arrlen(name) > 2)
		return (display_cd_error(name[1], 1, shell, oldfd));
	if (ft_arrlen(name) < 2)
	{
		if (chdir(home->value) == -1)
			return (display_cd_error(home->value, 3, shell, oldfd));
	}
	else if (chdir(name[1]) == -1)
		return (display_cd_error(name[1], 3, shell, oldfd));
	update_pwd(shell);
	reset_output(is_pipe, oldfd);
	return (1);
}
