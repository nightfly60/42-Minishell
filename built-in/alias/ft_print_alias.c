/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alias.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:21:20 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 17:11:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

/*Print la liste d'alias complete sous le format : "name='content'".*/
void	ft_print_alias(t_alias *alias_list)
{
	while (alias_list && alias_list->name)
	{
		ft_printf("%s='%s'\n", alias_list->name, alias_list->content);
		alias_list = alias_list->next;
	}
}
