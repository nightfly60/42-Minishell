/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unalias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:45:03 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 16:02:44 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

/*Free un alias et son contenu.*/
static void	ft_alias_delone(t_alias *alias, void (*del)(void *))
{
	if (!alias)
		return ;
	del(alias->content);
	del(alias->name);
	free(alias);
	alias = NULL;
}

/*Change les pointeurs de previous de next + next de previous 
pour rattacher la chaine correctement sans l'elem.*/
static void	ft_reattach_alias(t_alias *previous, t_alias *next, t_alias **alias)
{
	if (previous)
		previous->next = next;
	else
		*alias = next;
	if (next)
		next->previous = previous;
}

static void err_display(char *del_name)
{
	ft_putstr_fd("unalias: ", STDERR_FILENO);
	ft_putstr_fd(del_name, STDERR_FILENO);
	ft_putstr_fd(": not found\n", STDERR_FILENO);
}

/*Retire un alias de la liste (l'alias avec le nom passe en arg).*/
static int	ft_unalias_one(char *del_name, t_alias **alias)
{
	t_alias	*current;
	t_alias	*previous;
	t_alias	*next;

	current = *alias;
	while (current)
	{
		if (current->name && !ft_strcmp(del_name, current->name))
		{
			previous = current->previous;
			next = current->next;
			ft_reattach_alias(previous, next, alias);
			ft_alias_delone(current, &free);
			return (0);
		}
		current = current->next;
	}
	err_display(del_name);
	return (1);
}

int ft_unalias(char **cmd, t_minishell *shell)
{
	int	i;

	shell->exit_status = 0;
	i = 1;
	if (ft_arrlen(cmd) == 1)
	{
		ft_putstr_fd("unalias: usage: unalias [-a] name [name ...]\n", STDERR_FILENO);
		shell->exit_status = 2;
	}
	while (cmd[i])
	{
		if (ft_unalias_one(cmd[i], &shell->alias) == 1)
			shell->exit_status = 1;
		i++;
	}
	return (1);
}
