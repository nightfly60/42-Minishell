/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:57:59 by edurance          #+#    #+#             */
/*   Updated: 2025/08/20 16:10:39 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

static t_redir	*make_redir(char *name, t_redirtype type)
{
	t_redir	*redirect;
	int		i;

	redirect = malloc(sizeof(t_redir));
	if (!redirect)
		return (NULL);
	redirect->name = ft_strdup(name);
	if (type == HEREDOC)
	{
		i = 0;
		while (name[i])
		{
			if (name[i] == '"' || name[i] == '\'')
				type = HEREDOC_NO_EXP;
			i++;
		}
	}
	redirect->type = type;
	return (redirect);
}

/*Si on est sur un operateur, on remplis la bonne section avec le nom/EOF etc.*/
static int	handle_operators(int i, char **tokens, t_cmd_block *cmd_block)
{
	t_list	*elem;

	if (!ft_strcmp(tokens[i], "<") && tokens[i + 1])
	{
		elem = ft_lstnew(make_redir(tokens[i + 1], INFILE));
		ft_lstadd_back(&cmd_block->in, elem);
	}
	else if (!ft_strcmp(tokens[i], ">") && tokens[i + 1])
	{
		elem = ft_lstnew(make_redir(tokens[i + 1], OUTFILE));
		ft_lstadd_back(&cmd_block->out, elem);
	}
	else if (!ft_strcmp(tokens[i], ">>") && tokens[i + 1])
	{
		elem = ft_lstnew(make_redir(tokens[i + 1], APPEND));
		ft_lstadd_back(&cmd_block->out, elem);
	}
	else if (!ft_strcmp(tokens[i], "<<") && tokens[i + 1])
	{
		elem = ft_lstnew(make_redir(tokens[i + 1], HEREDOC));
		ft_lstadd_back(&cmd_block->in, elem);
	}
	else
		return (0);
	return (1);
}

/*Malloc et mettre a null tout*/
static t_cmd_block	*new_cmd(void)
{
	t_cmd_block	*cmd_block;

	cmd_block = malloc(sizeof(t_cmd_block));
	if (!cmd_block)
		return (NULL);
	cmd_block->in = NULL;
	cmd_block->out = NULL;
	cmd_block->cmds = NULL;
	return (cmd_block);
}

/*On compte le nb d'args
	-> dup. On evite les | et on gere les operateurs dans la structure.*/
static t_cmd_block	*parse_cmd(char **tokens, int *i)
{
	t_cmd_block	*cmd;
	char		**args;
	int			j;

	cmd = new_cmd();
	j = 0;
	args = malloc(sizeof(char *) * (count_cmd_args(tokens, *i) + 1));
	if (!args)
		return (NULL);
	while (tokens[*i] && ft_strcmp(tokens[*i], "|"))
	{
		if (handle_operators(*i, tokens, cmd))
			(*i)++;
		else
		{
			args[j] = ft_strdup(tokens[*i]);
			j++;
		}
		(*i)++;
	}
	args[j] = NULL;
	cmd->cmds = args;
	if (tokens[*i] && !ft_strcmp(tokens[*i], "|"))
		(*i)++;
	return (cmd);
}

/*Remplis la structure t_cmd_block etliste chainee pour chaque cmd (args,
	infile etc.)*/
void	parse_pipeline(t_minishell *shell)
{
	t_list	*new_block;
	int		i;

	i = 0;
	while ((shell->tokens) && (shell->tokens)[i])
	{
		new_block = ft_lstnew(parse_cmd((shell->tokens), &i));
		ft_lstadd_back(&(shell->cmd_block), new_block);
	}
	return ;
}
