/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:24:39 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/16 15:10:06 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

t_env	*find_var(char *name, t_env **first, int name_len)
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
