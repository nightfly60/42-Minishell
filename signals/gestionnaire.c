/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestionnaire.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:08:29 by edurance          #+#    #+#             */
/*   Updated: 2025/09/03 15:42:07 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signals.h"

void	gestionnaire(int signal)
{
	if (signal == SIGINT)
		g_event = 1;
	handle_signal();
}
