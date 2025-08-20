/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:31:28 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/19 15:59:28 by edurance         ###   ########.fr       */
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

/*	lst_iter mais avec le content et le shell	*/
void	exp_file(t_list *lst, void (*f)(void *, t_minishell *), t_minishell *s)
{
	while (lst)
	{
		f(lst->content, s);
		lst = lst->next;
	}
}

/*	Expand les noms de fichiers	*/
static void	ft_expand_filename(void *content, t_minishell *shell)
{
	t_redir	*redir;
	char	*filename;

	redir = (t_redir *)content;
	filename = redir->name;
	if (filename[0] == '"')
		double_quote(&(redir->name), shell->env);
	else if (filename[0] == '\'')
		single_quote(&(redir->name));
	else
		ft_word_expansion(&(redir->name), shell->env);
	return ;
}

/*	Parcours tous les commandes block et expand les char **.	*/
void	ft_expand_cmds(t_minishell *shell)
{
	t_list		*lst;
	t_cmd_block	*command;

	lst = shell->cmd_block;
	while (lst)
	{
		command = (t_cmd_block *)lst->content;
		ft_expand_tokens(command->cmds, shell->env);
		exp_file(command->in, &ft_expand_filename, shell);
		exp_file(command->out, &ft_expand_filename, shell);
		lst = lst->next;
	}
}
