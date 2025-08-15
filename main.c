/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:15:26 by edurance          #+#    #+#             */
/*   Updated: 2025/08/15 16:45:42 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_minishell(char *line)
{
	free(line);
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

int	main(void)
{
	char	*line;
	char	**args;
	t_alias	*alias;

	alias = NULL;
	rl_clear_history();
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, "exit"))
		{
			exit_minishell(line);
		}
		add_history(line);
		if (!quotes_checker(line))
		{
			ft_printf("minishell: %s: syntax error\n", line);
			free(line);
			line = NULL;
			continue ;
		}
		else if (!ft_strncmp(line, "alias", 5))
		{
			ft_alias(ft_split(line, ' '), &alias);
		}
		else if (!ft_strncmp(line, "unalias", 7))
		{
			char **unalias_args = ft_split(line, ' ');
			ft_unalias(unalias_args[1], &alias);
		}
		else
		{
			args = get_tokens(line);
			print_str_table(args);
			ft_printf("\n After Alias Expansion\n");
			ft_alias_expansion(args, alias);
			print_str_table(args);
			ft_printf("\nAfter merged tokens\n");
			args = ft_merge_tokens(line, args);
			print_str_table(args);
			ft_freeall(args);
		}
		free(line);
		line = NULL;
	}
	rl_clear_history();
	return (0);
}
