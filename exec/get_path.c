/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:46:06 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/22 13:07:31 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

static void	free_split_command(char ***split, char **command)
{
	free(*command);
	ft_freeall(*split);
	*command = NULL;
	*split = NULL;
}

static char	*check_command(char *command, t_minishell *shell)
{
	int		i;
	char	**paths;
	char	*check_path;
	char	*hash_command;

	if (!find_var("PATH", &(shell->env)))
		return (NULL);
	paths = ft_split(find_var("PATH", &(shell->env))->value, ':');
	i = 0;
	hash_command = ft_strjoin("/", command);
	while (paths[i])
	{
		check_path = ft_strjoin(paths[i], hash_command);
		if (access(check_path, F_OK | X_OK) == 0)
		{
			free_split_command(&paths, &hash_command);
			return (check_path);
		}
		free(check_path);
		i++;
	}
	free_split_command(&paths, &hash_command);
	return (NULL);
}

char	*get_path(char *command, t_minishell *shell)
{
	char	*command_path;

	if (!command[0])
		command_path = check_command("", shell);
	else if (ft_strchr(command, '/'))
		return (ft_strdup(command));
	else
		command_path = check_command(command, shell);
	return (command_path);
}
