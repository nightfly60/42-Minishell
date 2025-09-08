/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestionnaire.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:08:29 by edurance          #+#    #+#             */
/*   Updated: 2025/09/07 12:28:03 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

void	gestionnaire(int signal)
{
	if (signal == SIGINT)
		g_event = 1;
	handle_signal();
}

void	gest_sigint(int signal)
{
	if (signal == SIGINT)
	{
		get_next_line(-1);
		get_shell(NULL)->exit_status = 130;
		exit_minishell(get_shell(NULL));
	}
	return ;
}
