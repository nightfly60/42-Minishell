/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:15:26 by edurance          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/19 11:37:49 by edurance         ###   ########.fr       */
=======
/*   Updated: 2025/08/18 17:01:19 by edurance         ###   ########.fr       */
>>>>>>> anas
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
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

=======
>>>>>>> anas
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

<<<<<<< HEAD
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

void print_file(void *redir)
{
	char *test;
	t_redir *redirections = (t_redir *)redir;

	if (redirections->type == INFILE)
		test = "infile";
	else if (redirections->type == OUTFILE)
		test = "outfile";
	else if (redirections->type == HEREDOC)
		test = "heredoc";
	else
		test = "append";
	ft_printf("%s: %s\n", test, redirections->name);
}

void print_cmd(void *commands)
{
	t_cmd_block *cmd = (t_cmd_block *)commands;
	print_str_table(cmd->cmds);
	ft_lstiter(cmd->in, &print_file);
	ft_lstiter(cmd->out, &print_file);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*shell;
	char		**cmd_unalias;
=======
int	main(int ac, char **av, char **env)
{
	t_minishell	*shell;
>>>>>>> anas

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
<<<<<<< HEAD
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
=======
		add_history((shell->line));
		shell->tokens = get_tokens(shell->line);
		if (parse_errors(shell))
			continue ;
		if (!(shell->line) || !ft_strcmp((shell->line), "exit"))
			exit_minishell(shell);
>>>>>>> anas
		if (!ft_strncmp((shell->line), "alias", 5))
		{
			ft_alias(ft_split((shell->line), ' '), &(shell->alias));
		}
<<<<<<< HEAD
		else if (!ft_strncmp((shell->line), "unalias", 5))
		{
			cmd_unalias = ft_split(shell->line, ' ');
			ft_unalias(cmd_unalias[1], &shell->alias);
			ft_freeall(cmd_unalias);
		}
=======
>>>>>>> anas
		else if (!ft_strncmp((shell->line), "env", 3))
			print_env(shell);
		else
		{
<<<<<<< HEAD
			shell->tokens = get_tokens(shell->line);
			ft_printf("GET_TOKENS\n");
			print_str_table(shell->tokens);
			ft_printf("\nALIAS EXPANSION\n");
			ft_alias_expansion(shell->tokens, shell->alias);
			print_str_table(shell->tokens);
			printf("-----------------CMD BLOCKS-----------------\n");
			parse_pipeline(shell);
			ft_lstiter(shell->cmd_block, &print_cmd);
		}
		free(shell->line);
		shell->line = NULL;
	}
	rl_clear_history();
=======
			ft_alias_expansion(shell->tokens, shell->alias);
			ft_expand_tokens(shell->tokens, shell->env);
		}
		free_line(shell);
	}
>>>>>>> anas
	return (0);
}
