/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_alias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:20:20 by edurance          #+#    #+#             */
/*   Updated: 2025/08/15 10:59:09 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

/*Trouve l'alias avec le nom passe en argument.*/
int	find_alias(t_alias *alias_list, char *name)
{
	t_alias	*current;

	current = alias_list;
	while (current && current->name)
	{
		if (!ft_strcmp(current->name, name))
		{
			ft_printf("%s='%s'\n", current->name, current->content);
			return (1);
		}
		current = current->next;
	}
	return (0);
}
