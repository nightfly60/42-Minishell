/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:built-in/alias/ft_print_alias.c
/*   ft_print_alias.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:21:20 by edurance          #+#    #+#             */
/*   Updated: 2025/08/15 10:53:48 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

/*Print la liste d'alias complete sous le format : "name='content'".*/
void	ft_print_alias(t_alias *alias_list)
{
	while (alias_list && alias_list->name)
	{
		printf("%s='%s'\n", alias_list->name, alias_list->content);
		alias_list = alias_list->next;
	}
========
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:16:07 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/14 17:45:55 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*	compte le nombre de tokens dans la ligne	*/
int	count_tokens(char *s)
{
	int	i;
	int	count;
	int	add_index;

	count = 0;
	i = 0;
	while (s[i])
	{
		add_index = is_quote(&s[i]);
		if (add_index)
			i += add_index;
		else if (is_operator(&s[i]))
			i += is_operator(&s[i]);
		else if (!ft_isspace(s[i]) && (!s[i + 1] || ft_isspace(s[i + 1])
				|| is_quote(&s[i + 1]) || is_operator(&s[i + 1])))
			i++;
		else
		{
			i++;
			continue ;
		}
		count++;
	}
	return (count);
>>>>>>>> anas:parsing/tokenize/count_token.c
}
