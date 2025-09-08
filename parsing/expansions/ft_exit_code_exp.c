/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_code_exp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:40:35 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/05 17:06:16 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*	Compte le nombre de $? a expand.	*/
static int	count_exit(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] && s[i] + 1)
	{
		if (s[i] == '$' && s[i + 1] == '?')
			count++;
		i++;
	}
	return (count);
}

static char	*replace_exit_code(char *s, char *exit_code, int len, int nb_exit)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	res = malloc(sizeof(char) * (ft_strlen(s) - nb_exit * 2 + nb_exit * len
				+ 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '$' && s[i + 1] && s[i + 1] == '?')
		{
			k = 0;
			while (exit_code[k])
				res[j++] = exit_code[k++];
			i += 2;
		}
		else
			res[j++] = s[i++];
	}
	res[j] = 0;
	return (res);
}

/*	Expand les $? en code d'erreur.	*/
void	expand_exit_code(char **s, t_minishell *shell)
{
	char	*exit_code;
	char	*replaced;

	if (!count_exit(*s))
		return ;
	exit_code = ft_itoa(shell->exit_status);
	replaced = replace_exit_code(*s, exit_code, ft_intlen(shell->exit_status),
			count_exit(*s));
	free(exit_code);
	free(*s);
	*s = replaced;
}
