/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alias_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:19:47 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 17:11:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*Renvoie la position dans la liste de l'alias avec le nom passe en arg.
	-1 Si il n'existe pas.*/
static int	ft_is_alias(char *arg_name, t_alias *alias)
{
	t_alias	*current;
	int		i;

	current = alias;
	i = 0;
	while (current)
	{
		if (current->name && !ft_strcmp(arg_name, current->name))
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

/*Modifie chaque nom d'alias en sa valeur.
-> alias elena=cat
-> elena main.c = cat main.c*/
void	ft_alias_expansion(char **args, t_alias *alias)
{
	t_alias	*current;
	int		j;
	int		i;
	int		k;

	i = 0;
	current = alias;
	while (args[i])
	{
		if (!i || !ft_strcmp(args[i - 1], "|"))
		{
			j = ft_is_alias(args[i], current);
			if (j != -1)
			{
				k = 0;
				while (k++ < j)
					current = current->next;
				free(args[i]);
				args[i] = ft_strdup(current->content);
				current = alias;
			}
		}
		i++;
	}
}
