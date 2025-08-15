/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:31:28 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/15 16:53:26 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static char	*single_quote(char *s)
{
	char	*res;
	int		i;

	i = 1;
	res = malloc(sizeof(char) * (strlen(s) - 1));
	if (!res)
		return (NULL);
	while (s[i + 1])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	free(s);
	return (res);
}

int	main(void)
{
	char	*quote;
	char	*exp;

	quote = strdup("\'salut les $amis ca va ???\'");
	exp = single_quote(quote);
	printf("%s\n", exp);
	free(exp);
}
