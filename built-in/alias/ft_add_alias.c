/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_alias.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:23:01 by edurance          #+#    #+#             */
/*   Updated: 2025/08/15 11:04:25 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

/*Si la liste n'existe pas ou que c'est le premier dans l'ordre alphabetique
	-> ajoute.*/
static int	add_alias_front(t_alias **alias_list, t_alias *new_alias)
{
	if (!*alias_list || !(*alias_list)->name || ft_strcmp(new_alias->name,
			(*alias_list)->name) < 0)
	{
		new_alias->next = *alias_list;
		new_alias->previous = NULL;
		if (*alias_list)
			(*alias_list)->previous = new_alias;
		*alias_list = new_alias;
		return (1);
	}
	return (0);
}

/*On trouve la bonne position pour que ce soit dans
l'ordre alaphabetique et on le rajoute.*/
static void	add_alias_sorted(t_alias **alias_list, t_alias *new_alias)
{
	t_alias	*current;
	t_alias	*previous;

	if (add_alias_front(alias_list, new_alias))
		return ;
	previous = *alias_list;
	current = (*alias_list)->next;
	while (current && current->name && ft_strcmp(new_alias->name,
			current->name) > 0)
	{
		previous = current;
		current = current->next;
	}
	previous->next = new_alias;
	new_alias->next = current;
	new_alias->previous = previous;
	if (current)
		current->previous = new_alias;
}

/*Ajoute un alias avec le nom et le content dans la liste chainee.*/
void	ft_add_alias(char *name, char *content, t_alias **alias_list)
{
	t_alias	*new_alias;

	if (modify_alias(*alias_list, name, content))
		return ;
	new_alias = malloc(sizeof(t_alias));
	if (!new_alias)
		return ;
	new_alias->name = ft_strdup(name);
	new_alias->content = ft_strdup(content);
	new_alias->next = NULL;
	add_alias_sorted(alias_list, new_alias);
}
