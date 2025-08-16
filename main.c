/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:15:26 by edurance          #+#    #+#             */
/*   Updated: 2025/08/16 14:59:44 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_minishell(t_minishell *shell)
{
	ft_freeall(shell->tokens);
	free(shell->line);
	rl_clear_history();
	clear_alias(shell->alias, &free);
	clear_env(shell->env, &free);
	free(shell);
	ft_printf("exit\n");
	exit(0);
}

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (signal == SIGQUIT)
		return ;
}

static void	init_shell(t_minishell *shell, char **env)
{
	shell->tokens = NULL;
	shell->line = NULL;
	shell->alias = NULL;
	shell->env = NULL;
	rl_clear_history();
	shell->prompt = "minishell > ";
	copy_env(shell, env);
}

void	print_str_tab_wrapper(void *content)
{
	print_str_table((char **)content);
}

void	print_str_wrapper(void *content)
{
	static int	idx = 0;

	printf("-> On passe sur l'élément %d de la liste\n", idx++);
	printf("value = '%s'\n", (char *)content);
}

void	ft_print_cmd(t_cmd_block *elem)
{
	if (!elem)
	{
		printf("Nothing in the cmd block\n");
		return ;
	}
	printf("\nPRINT CMD\n");
	printf("Infile = %s\n", elem->infile);
	printf("Outfile = %s\n", elem->outfile);
	printf("Heredoc EOF = %s\n", elem->heredoc_eof);
	printf("Append = %s\n", elem->append);
	ft_lstiter(elem->cmds, print_str_wrapper);
}

t_cmd_block	*init_cmd_block(char **tokens)
{
	t_cmd_block	*cmd_block;
	t_list		*cmds;
	int			i;
	int			j;

	cmd_block = malloc(sizeof(t_cmd_block));
	if (!cmd_block)
		return (NULL);
	i = 0;
	j = 0;
	cmds = NULL;
	while (tokens[i])
	{
		if (!ft_strcmp(tokens[i], "<") && tokens[i + 1])
			cmd_block->infile = ft_strdup(tokens[++i]);
		else if (!ft_strcmp(tokens[i], ">") && tokens[i + 1])
			cmd_block->outfile = ft_strdup(tokens[++i]);
		else if (!ft_strcmp(tokens[i], "<<") && tokens[i + 1])
			cmd_block->heredoc_eof = ft_strdup(tokens[++i]);
		else if (!ft_strcmp(tokens[i], ">>") && tokens[i + 1])
			cmd_block->append = ft_strdup(tokens[++i]);
		else
		{
			printf("ici\n");
			ft_lstadd_back(&cmds, ft_lstnew(ft_strdup(tokens[i])));
		}
		i++;
	}
	cmd_block->cmds = cmds;
	return (cmd_block);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*shell;
	char		**cmd_unalias;
	t_cmd_block	*cmd_block;

	(void)ac;
	(void)av;
	shell = malloc(sizeof(t_minishell));
	if (!shell)
		return (1);
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	init_shell(shell, env);
	while (1)
	{
		shell->line = readline(shell->prompt);
		if (!(shell->line) || !ft_strcmp((shell->line), "exit"))
		{
			exit_minishell(shell);
		}
		add_history((shell->line));
		if (!quotes_checker((shell->line)))
		{
			ft_printf("minishell: %s: syntax error\n", (shell->line));
			free((shell->line));
			(shell->line) = NULL;
			continue ;
		}
		if (!ft_strncmp((shell->line), "alias", 5))
		{
			ft_alias(ft_split((shell->line), ' '), &(shell->alias));
		}
		else if (!ft_strncmp((shell->line), "unalias", 5))
		{
			cmd_unalias = ft_split(shell->line, ' ');
			ft_unalias(cmd_unalias[1], &shell->alias);
			ft_freeall(cmd_unalias);
		}
		else if (!ft_strncmp((shell->line), "env", 3))
			print_env(shell);
		else
		{
			shell->tokens = get_tokens(shell->line);
			print_str_table(shell->tokens);
			ft_printf("\n\n");
			ft_alias_expansion(shell->tokens, shell->alias);
			print_str_table(shell->tokens);
			cmd_block = init_cmd_block(shell->tokens);
			ft_print_cmd(cmd_block);
		}
		free(shell->line);
		shell->line = NULL;
	}
	rl_clear_history();
	return (0);
}
