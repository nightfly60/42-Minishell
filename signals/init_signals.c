/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:09:53 by edurance          #+#    #+#             */
/*   Updated: 2025/09/03 15:10:04 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

void	init_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = gestionnaire;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}
