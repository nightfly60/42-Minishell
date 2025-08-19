/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:16:07 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/18 15:15:13 by aabouyaz         ###   ########.fr       */
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
	while (s && s[i])
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
}
