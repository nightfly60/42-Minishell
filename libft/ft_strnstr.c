/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:43:27 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/04/26 14:18:24 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, unsigned long len)
{
	unsigned long	i;
	unsigned long	j;
	char			*s;

	i = 0;
	j = 0;
	s = (char *)big;
	if (!s[0] && little[0] && len <= 0)
		return (0);
	if ((!s[0] && len <= 0) || !little[0])
		return (s);
	while (s[i] && i < len)
	{
		if (little[j] == s[i])
		{
			while (little[j] == s[i + j] && (i + j) < len && little[j])
				j++;
		}
		if (little[j] == '\0')
			return (&s[i]);
		j = 0;
		i++;
	}
	return (0);
}
