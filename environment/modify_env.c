/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:33:01 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/05 13:12:43 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"

t_env	*modify_env(char *name, char *new_value, t_env **first)
{
	t_env	*res;

	res = find_var(name, first);
	if (res)
	{
		free(res->value);
		res->value = ft_strdup(new_value);
		return (res);
	}
	res = new_env(name, new_value);
	env_add_back(first, res);
	return (res);
}
