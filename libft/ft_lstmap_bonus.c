/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:31:09 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/04/27 11:52:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*cont;
	t_list	*current;
	t_list	*begin;

	begin = NULL;
	while (lst)
	{
		cont = f(lst->content);
		current = ft_lstnew(cont);
		if (!current)
		{
			del(cont);
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, current);
		lst = lst->next;
	}
	return (begin);
}
