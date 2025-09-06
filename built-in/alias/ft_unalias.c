/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unalias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:45:03 by edurance          #+#    #+#             */
/*   Updated: 2025/09/06 14:10:02 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

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
	print_error("unalias: ", del_name, ": not found\n");
	return (1);
}

int	ft_unalias(t_cmd_block *cmd, t_minishell *shell, int is_pipe)
{
	int		i;
	char	**args;
	int		oldfd;

	oldfd = builtin_outfile(cmd, is_pipe);
	args = cmd->cmds;
	shell->exit_status = 0;
	i = 1;
	if (ft_arrlen(args) == 1)
	{
		ft_putstr_fd("unalias: usage: unalias [-a] name [name ...]\n",
			STDERR_FILENO);
		shell->exit_status = 2;
	}
	while (args[i])
	{
		if (ft_unalias_one(args[i], &shell->alias) == 1)
			shell->exit_status = 1;
		i++;
	}
	reset_output(is_pipe, oldfd);
	return (1);
}
