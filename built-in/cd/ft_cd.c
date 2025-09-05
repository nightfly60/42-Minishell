/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:15:18 by edurance          #+#    #+#             */
/*   Updated: 2025/09/05 12:27:03 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

/*affiche la bonne erreur*/
static int	display_cd_error(char *name, int error, t_minishell *shell)
{
	if (error == 1)
		ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd("cd: HOME not set\n", STDERR_FILENO);
	else if (error == 3)
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(name, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	shell->exit_status = 1;
	return (1);
}

/*built in cd*/
int	ft_cd(char **name, t_minishell *shell)
{
	t_env	*home;
	t_env	*pwd;
	char	*cwd;

	shell->exit_status = 0;
	home = find_var("HOME", &shell->env);
	if (!home || !home->value)
		return (display_cd_error(name[1], 2, shell));
	if (ft_arrlen(name) > 2)
		return (display_cd_error(name[1], 1, shell));
	if (ft_arrlen(name) < 2)
	{
		if (chdir(home->value) == -1)
			return (display_cd_error(home->value, 3, shell));
	}
	else if (chdir(name[1]) == -1)
		return (display_cd_error(name[1], 3, shell));
	cwd = getcwd(NULL, 0);
	pwd = find_var("PWD", &shell->env);
	modify_env("OLDPWD", pwd->value, &shell->env);
	modify_env("PWD", cwd, &shell->env);
	free(cwd);
	free(shell->pwd);
	shell->pwd = getcwd(NULL, 0);
	return (1);
}
