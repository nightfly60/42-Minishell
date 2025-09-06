/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_alias.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:58:31 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/04 17:11:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_built_in.h"

/*	Sert a liberer tous les alias	*/
void	clear_alias(t_alias *lst, void (*f)(void *))
{
	t_alias	*next;

	while (lst)
	{
		f(lst->content);
		f(lst->name);
		next = lst->next;
		f(lst);
		lst = next;
	}
}
