/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:01:35 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/17 15:15:05 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

t_env	*env_last(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	env_add_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = env_last(*lst);
	last->next = new;
	new->previous = last;
	new->next = NULL;
}

void	env_delone(t_env *elem, void (*del)(void *))
{
	t_env	*n_elem;
	t_env	*p_elem;

	if (!elem)
		return ;
	del(elem->name);
	del(elem->value);
	n_elem = elem->next;
	p_elem = elem->previous;
	n_elem->previous = p_elem;
	p_elem->next = n_elem;
	del(elem);
}

void	print_env(t_minishell *shell)
{
	t_env	*current;

	current = shell->env;
	while (current)
	{
		ft_printf("%s=%s\n", current->name, current->value);
		current = current->next;
	}
}

/*	Sert a liberer toutes les variables	*/
void	clear_env(t_env *lst, void (*f)(void *))
{
	t_env	*next;

	while (lst)
	{
		f(lst->value);
		f(lst->name);
		next = lst->next;
		f(lst);
		lst = next;
	}
}
