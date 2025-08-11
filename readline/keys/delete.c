/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:56:56 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/08/11 14:57:56 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_readline.h"

int	delete(char c, t_minishell *shell)
{
	static int	status = 0;

	if (c == 27 && status == 0)
		return (++status);
	else if (status == 1 && c == 91)
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
