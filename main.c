/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:51:48 by edurance          #+#    #+#             */
/*   Updated: 2025/08/10 19:40:58 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	readprint(t_minishell *shell)
{
	char	*line;

	while (1)
	{
		shell->line = malloc(sizeof(t_line));
		shell->line->newline = NULL;
		shell->line->index_hist = -1;
		line = ft_readline(shell->prompt, shell);
		free(line);
		free(shell->line->newline);
		free(shell->line);
		shell->line = NULL;
	}
}

int	main(void)
{
	t_minishell	*shell;

	shell = malloc(sizeof(t_minishell));
	shell->prompt = "minishell > ";
	shell->history = NULL;
	switch_terminal();
	readprint(shell);
	switch_terminal();
	ft_lstclear(&(shell->history), free);
	free(shell);
}
