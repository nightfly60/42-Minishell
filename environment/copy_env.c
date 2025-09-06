/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:36:41 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/05 15:42:58 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

/*	prends une ligne complete et renvoie son contenu avant  '='.	*/
static char	*get_var_name(char *s)
{
	char	*res;
	int		i;

	i = 0;
	res = strdup(s);
	while (res[i])
	{
		if (res[i] == '=')
		{
			res[i] = 0;
			break ;
		}
		i++;
	}
	return (res);
}

/*	copy dans le shell l'environnement passe en argument.	*/
void	copy_env(t_minishell *shell, char **env)
{
	int		i;
	char	*name;
	t_env	*new;
	char	*value;

	i = 0;
	while (env[i])
	{
		name = get_var_name(env[i]);
		if (getenv(name))
		{
			if (ft_strncmp(name, "SHLVL", 5) && ft_strncmp(name, "_", 1))
				new = new_env(name, getenv(name));
			else if (ft_strncmp(name, "_", 1))
			{
				value = ft_itoa(ft_atoi(getenv(name)) + 1);
				new = new_env(name, value);
				free(value);
			}
			env_add_back(&(shell->env), new);
		}
		free(name);
		i++;
	}
}

/*	crer un environnement si il y en avait pas de base.	*/
void	create_env(t_minishell *shell, char **env)
{
	t_env	*new;

	if (env[0])
		return ;
	shell->env = new_env("SHLVL", "1");
	new = new_env("PWD", shell->pwd);
	env_add_back(&(shell->env), new);
	new = new_env("OLDPWD", NULL);
	env_add_back(&(shell->env), new);
}
