/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:28:01 by edurance          #+#    #+#             */
/*   Updated: 2025/05/27 17:33:27 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	word_len(const char *s, char c, int j)
{
	int	i;
	int	count;
	int	n;

	i = 0;
	count = 0;
	n = 0;
	while (n < j - 1)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c)
			i++;
		n++;
	}
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	return (count);
}

static char	*point_word(int word, const char *s, char sep)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	str = (char *)s;
	count = 1;
	while (count < word)
	{
		while (str[i] == sep)
			i++;
		while (str[i] != sep)
			i++;
		count++;
	}
	while (str[i] == sep)
		i++;
	return (&str[i]);
}

char	**ft_split(char const *s, char sep)
{
	char	**res;
	int		current;

	current = 0;
	res = malloc(sizeof(char *) * (1 + count_words(s, sep)));
	if (!res)
		return (NULL);
	while (current < count_words(s, sep))
	{
		res[current] = malloc(sizeof(char) * word_len(s, sep, current + 1) + 1);
		if (!res[current])
		{
			ft_freeall(res);
			return (NULL);
		}
		ft_strlcpy(res[current], point_word(current + 1, s, sep),
			word_len(s, sep, current + 1) + 1);
		current++;
	}
	res[current] = NULL;
	return (res);
}
