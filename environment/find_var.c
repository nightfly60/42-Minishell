/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:24:39 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/17 14:54:45 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

/*	trouve et renvoie un element ayant le nom 'name'.	*/
t_env	*find_var(char *name, t_env **first)
{
	t_env	*current;

	current = *first;
	while (current)
	{
		if (current->name && !ft_strcmp(current->name, name))
			return (current);
		current = current->next;
	}
	return (NULL);
}

/*	trouve et renvoie un element ayant le nom 'name' et la len 'name_len'.	*/
t_env	*find_var_len(char *name, t_env **first, int name_len)
{
	t_env	*current;

	current = *first;
	while (current)
	{
		if (current->name && !ft_strncmp(current->name, name, name_len))
			return (current);
		current = current->next;
	}
	return (NULL);
}
