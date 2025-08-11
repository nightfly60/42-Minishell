/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:47:00 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/11 14:33:58 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

static void	arrow_left(t_minishell *shell)
{
	(void)shell;
	// if (line->st_col == actual pos)
	// 	return ;
	write(STDOUT_FILENO, "\x1b[1C", 4);
	return ;
}

static void	arrow_right(t_minishell *shell)
{
	(void)shell;
	// if (line->st_col == actual pos)
	// 	return ;
	write(STDOUT_FILENO, "\x1b[1D", 4);
	return ;
}

static void	arrow_up(t_minishell *shell)
{
	t_list	*history;

	if (shell->line->index_hist + 1 >= ft_lstsize(shell->history))
		return ;
	if ((shell->line->index_hist) == -1)
		shell->line->newline = ft_strdup(shell->line->buffer);
	(shell->line->index_hist)++;
	history = ft_lstget(shell->history, shell->line->index_hist);
	write(STDOUT_FILENO, "\x1b[2K\r", 5);
	ft_printf("%s", shell->prompt);
	write(STDOUT_FILENO, (char *)history->content,
		ft_strlen((char *)history->content) - 1);
	return ;
}

static void	arrow_down(t_minishell *shell)
{
	t_list	*history;

	if (shell->line->index_hist == -1)
		return ;
	if (shell->line->index_hist - 1 == -1)
	{
		shell->line->index_hist = -1;
		write(STDOUT_FILENO, "\x1b[2K\r", 5);
		ft_printf("%s%s", shell->prompt, shell->line->newline);
		return ;
	}
	(shell->line->index_hist)--;
	history = ft_lstget(shell->history, shell->line->index_hist);
	write(STDOUT_FILENO, "\x1b[2K\r", 5);
	ft_printf("%s", shell->prompt);
	write(STDOUT_FILENO, (char *)history->content,
		ft_strlen((char *)history->content) - 1);
	return ;
}

int	arrow(char c, t_minishell *shell)
{
	static int	status = 0;

	if (c == 27 && status == 0)
		return (++status);
	else if (status == 1 && c == 91)
		return (++status);
	else if (status == 2)
	{
		status = 0;
		if (c == 'A')
			arrow_up(shell);
		else if (c == 'B')
			arrow_down(shell);
		else if (c == 'C')
			arrow_left(shell);
		else if (c == 'D')
			arrow_right(shell);
		else
			return (0);
		return (1);
	}
	return (0);
}
