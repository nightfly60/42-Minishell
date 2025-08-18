/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:57:59 by edurance          #+#    #+#             */
/*   Updated: 2025/08/18 16:35:36 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*Si on est sur un operateur, on remplis la bonne section avec le nom/EOF etc.*/
static int	handle_operators(int i, char **tokens, t_cmd_block *cmd_block)
{
	t_list	*elem;

	if (!ft_strcmp(tokens[i], "<") && tokens[i + 1])
	{
		elem = ft_lstnew(ft_strdup(tokens[i + 1]));
		ft_lstadd_back(&cmd_block->infile, elem);
	}
	else if (!ft_strcmp(tokens[i], ">") && tokens[i + 1])
	{
		elem = ft_lstnew(ft_strdup(tokens[i + 1]));
		ft_lstadd_back(&cmd_block->outfile, elem);
	}
	else if (!ft_strcmp(tokens[i], ">>") && tokens[i + 1])
	{
		elem = ft_lstnew(ft_strdup(tokens[i + 1]));
		ft_lstadd_back(&cmd_block->append, elem);
	}
	else if (!ft_strcmp(tokens[i], "<<") && tokens[i + 1])
	{
		elem = ft_lstnew(ft_strdup(tokens[i + 1]));
		ft_lstadd_back(&cmd_block->heredoc_eof, elem);
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
	cmd_block->infile = NULL;
	cmd_block->outfile = NULL;
	cmd_block->append = NULL;
	cmd_block->heredoc_eof = NULL;
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
t_cmd_block	*parse_pipeline(char **tokens)
{
	t_cmd_block	*head;
	t_cmd_block	*current;
	t_cmd_block	*new_block;
	int			i;

	head = NULL;
	current = NULL;
	i = 0;
	while (tokens[i])
	{
		new_block = parse_cmd(tokens, &i);
		if (!head)
			head = new_block;
		else
			current->next = new_block;
		current = new_block;
	}
	return (head);
}
