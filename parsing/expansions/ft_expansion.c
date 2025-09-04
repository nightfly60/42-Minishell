/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:31:28 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/04 17:11:36 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*	Expand autant les quotes que les dquotes.	*/
void	ft_expand_tokens(char **tokens, t_minishell *shell)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '"')
			double_quote(&tokens[i], shell->env);
		else if (tokens[i][0] == '\'')
			single_quote(&tokens[i]);
		else
			ft_word_expansion(&tokens[i], shell->env);
		expand_exit_code(&tokens[i], shell);
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

static void	ft_expand_merged(char **merged, t_minishell *shell, int eof)
{
	char	**tokens;
	char	*res;
	int		i;
	char	*temp;

	i = 0;
	res = NULL;
	tokens = get_tokens(*merged);
	if (!eof)
		ft_expand_tokens(tokens, shell);
	else
		ft_expand_eof(tokens);
	while (tokens[i])
	{
		temp = res;
		res = ft_strjoin(res, tokens[i]);
		free(temp);
		i++;
	}
	ft_freeall(tokens);
	free(*merged);
	*merged = res;
}

/*	Expand les noms de fichiers	*/
static void	ft_expand_filename(void *content, t_minishell *shell)
{
	t_redir	*redir;

	redir = (t_redir *)content;
	if (redir->type == HEREDOC || redir->type == HEREDOC_NO_EXP)
		ft_expand_merged(&(redir->name), shell, 1);
	else
		ft_expand_merged(&(redir->name), shell, 0);
	return ;
}

/*	Parcours tous les commandes block et expand les char **.	*/
void	ft_expand_cmds(t_minishell *shell)
{
	t_list		*lst;
	t_cmd_block	*command;
	int			i;

	lst = shell->cmd_block;
	while (lst)
	{
		command = (t_cmd_block *)lst->content;
		i = 0;
		while ((command->cmds)[i])
		{
			ft_expand_merged(&(command->cmds)[i], shell, 0);
			i++;
		}
		exp_file(command->in, &ft_expand_filename, shell);
		exp_file(command->out, &ft_expand_filename, shell);
		lst = lst->next;
	}
}
