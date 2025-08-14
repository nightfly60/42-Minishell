/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:15:26 by edurance          #+#    #+#             */
/*   Updated: 2025/08/14 17:34:17 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exit_minishell(char *line)
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
	t_alias *alias = malloc(sizeof(t_alias));
	if (!alias)
		return (1);
	alias->name = NULL;
	alias->content = NULL;
	alias->next = NULL;
	alias->previous = NULL;

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
		if (!ft_strncmp(line, "alias", 5))
			ft_alias(ft_split(line, ' '), &alias);
		free(line);
		line = NULL;
	}
	rl_clear_history();
	return (0);
}
