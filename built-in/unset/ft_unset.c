/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:45:22 by edurance          #+#    #+#             */
/*   Updated: 2025/09/06 14:18:40 by edurance         ###   ########.fr       */
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
int	ft_unset(t_cmd_block *cmd, t_minishell *shell, int is_pipe)
{
	char	**args;
	int		i;
	t_env	*to_del;
	t_env	*previous;
	int		oldfd;

	oldfd = builtin_outfile(cmd, is_pipe);
	args = cmd->cmds;
	i = 1;
	while (args[i])
	{
		to_del = find_var(args[i], &shell->env);
		if (!to_del)
		{
			i++;
			continue ;
		}
		previous = to_del->previous;
		ft_reattach_env(previous, to_del->next, &shell->env);
		env_delone(to_del, &free);
		i++;
	}
	shell->exit_status = 0;
	reset_output(is_pipe, oldfd);
	return (1);
}
