/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:15:18 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 15:18:05 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

/*affiche la bonne erreur*/
static int	display_cd_error(char *name, int error, t_minishell *shell)
{
	if (error == 1)
		ft_printf("pacoshell: cd: too many arguments");
	else if (error == 2)
		ft_printf("pacoshell: cd: HOME not set\n");
	else if (error == 3)
		ft_printf("pacoshell: cd: %s: No such file or directory\n", name);
	shell->exit_status = 1;
	return (1);
}

/*built in cd*/
int	ft_cd(char **name, t_minishell *shell)
{
	t_env	*home;

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
	free(shell->pwd);
	shell->pwd = getcwd(NULL, 0);
	shell->exit_status = 0;
	return (1);
}
