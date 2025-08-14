/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_alias.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:22:11 by edurance          #+#    #+#             */
/*   Updated: 2025/08/14 17:34:49 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

int	modify_alias(t_alias *alias_list, char *name, char *content)
{
	t_alias	*current;

	current = alias_list;
	while (current)
	{
		if (current->name && !ft_strcmp(current->name, name))
		{
			if (current->content)
				free(current->content);
			current->content = ft_strdup(content);
			return (1);
		}
		current = current->next;
	}
	return (0);
}
