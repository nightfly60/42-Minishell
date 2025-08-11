/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:50:25 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/11 14:53:40 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

int	backspace(char c, t_minishell *shell)
{
	(void)shell;
	if (c != 127)
		return (0);
	write(STDOUT_FILENO, "\b \b", 3);
	return (1);
}
