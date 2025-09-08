/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:30:11 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/15 15:33:15 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

/*	retourne une nouvelle structure env	*/
t_env	*new_env(char *name, char *value)
{
	t_env	*res;

	res = malloc(sizeof(t_env));
	if (!res)
		return (NULL);
	res->name = ft_strdup(name);
	res->value = ft_strdup(value);
	res->next = NULL;
	res->previous = NULL;
	return (res);
}
