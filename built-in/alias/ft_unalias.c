/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unalias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:45:03 by edurance          #+#    #+#             */
/*   Updated: 2025/08/15 16:53:58 by edurance         ###   ########.fr       */
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

/*Change les pointeurs de previous de next et next de previous pour rattacher la chaine correctement sans l'elem.*/
static void ft_reattach_alias(t_alias *previous, t_alias *next, t_alias **alias)
{
	if (previous)
		previous->next = next;
	else
		*alias = next;
	if (next)
		next->previous = previous;
}

/*Retire un alias de la liste (l'alias avec le nom passe en arg).*/
void	ft_unalias(char *del_name, t_alias **alias)
{
	t_alias	*current;
	t_alias	*previous;
	t_alias	*next;

	current = *alias;
	if (!del_name)
	{
		ft_printf("unalias: usage: unalias [-a] name [name ...]\n");
		return ;
	}
	while (current)
	{
		if (current->name && !ft_strcmp(del_name, current->name))
		{
			previous = current->previous;
			next = current->next;
			ft_reattach_alias(previous, next, alias);
			ft_alias_delone(current, &free);
			return ;
		}
		current = current->next;
	}
	ft_printf("minishell: unalias: %s: not found\n", del_name);
}
