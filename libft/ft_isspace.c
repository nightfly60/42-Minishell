/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:built-in/alias/find_alias.c
/*   find_alias.c                                       :+:      :+:    :+:   */
========
/*   ft_isspace.c                                       :+:      :+:    :+:   */
>>>>>>>> anas:libft/ft_isspace.c
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:built-in/alias/find_alias.c
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
========
/*   Created: 2025/08/14 12:47:21 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/14 12:49:14 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	char	*spaces;
	int		i;

	i = 0;
	spaces = " \f\n\r\t\v";
	while (spaces[i])
	{
		if (spaces[i] == c)
			return (1);
		i++;
>>>>>>>> anas:libft/ft_isspace.c
	}
	return (0);
}
