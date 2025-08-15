/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:15:36 by edurance          #+#    #+#             */
/*   Updated: 2025/08/15 10:57:34 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

/*Verifie si il y a bien un nom=valeur et non juste =valeur.*/
static int	check_eq(char *args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (args[i] == '=')
		{
			j = 1;
			i++;
			break ;
		}
		i++;
	}
	if (i == j)
		return (0);
	return (1);
}

/*Si il y a un '=' et qu'il y a un nom -> modifie ou ajoute un alias.
Si il y a pas de '=' ou qu'il y en a un et pas de nom
	-> on essaie de le trouver et on l'affiche, sinon erreur.*/
static int	handle_alias(t_alias **alias_list, char *args)
{
	char	*name;
	char	*content;
	char	*eq;

	if (!ft_strchr(args, '=') || !check_eq(args))
	{
		if (!find_alias(*alias_list, args))
		{
			ft_printf("minishell: alias: %s: not found\n", args);
			return (0);
		}
	}
	else
	{
		eq = ft_strchr(args, '=');
		*eq = '\0';
		name = args;
		content = eq + 1;
		ft_add_alias(name, content, alias_list);
	}
	return (1);
}

/*Reproduction de la commande alias en bash. Si il y a qu'un seul arg
	-> print ("alias"). Si il y en a deux,
	on appelle la commande alias pour savoir si on doit :
1. Changer ou ajouter un alias.
2. Afficher un alias en particulier.*/
int	ft_alias(char **args, t_alias **alias_list)
{
	int	i;
	int	arg_count;

	i = 0;
	arg_count = ft_arrlen(args);
	if (arg_count == 1)
	{
		ft_print_alias(*alias_list);
		return (0);
	}
	else if (arg_count == 2)
	{
		if (!handle_alias(alias_list, args[1]))
			return (0);
	}
	return (1);
}
