/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:31:28 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/19 13:01:18 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*	Expand autant les quotes que les dquotes.	*/
static void	ft_expand_tokens(char **tokens, t_env *env)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '"')
			double_quote(&tokens[i], env);
		else if (tokens[i][0] == '\'')
			single_quote(&tokens[i]);
		else
			ft_word_expansion(&tokens[i], env);
		i++;
	}
}

/*	Parcours tous les commande bloc et expand les char **.	*/
void	ft_expand_cmds(t_minishell *shell)
{
	t_list		*lst;
	t_cmd_block	*command;

	lst = shell->cmd_block;
	while (lst)
	{
		command = (t_cmd_block *)lst->content;
		ft_expand_tokens(command->cmds, shell->env);
		lst = lst->next;
	}
}
