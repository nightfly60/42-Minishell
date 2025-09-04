/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:07:02 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 17:11:06 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H

# include "minishell.h"
# include <signal.h>

extern volatile sig_atomic_t	g_event;

int								handle_signal(void);
void							gestionnaire(int signal);
void							init_signals(void);

#endif
