/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:45:22 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 17:11:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

/*retirer un elem de l'env*/
static void	env_delone(t_env *env, void (*del)(void *))
{
	if (!env)
		return ;
	del(env->name);
	del(env->value);
	free(env);
	env = NULL;
}

/*rattacher la liste chainnee pour del*/
static void	ft_reattach_env(t_env *previous, t_env *next, t_env **env)
{
	if (previous)
		previous->next = next;
	else
		*env = next;
	if (next)
		next->previous = previous;
}

/*built in unset -> retirer une var de l'env*/
int	ft_unset(char **cmd, t_minishell *shell)
{
	int		i;
	t_env	*to_del;
	t_env	*previous;
	t_env	*next;

	i = 1;
	while (cmd[i])
	{
		to_del = find_var(cmd[i], &shell->env);
		if (!to_del)
		{
			i++;
			continue ;
		}
		previous = to_del->previous;
		next = to_del->next;
		ft_reattach_env(previous, next, &shell->env);
		env_delone(to_del, &free);
		i++;
	}
	shell->exit_status = 0;
	return (1);
}
