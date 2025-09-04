/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edurance <edurance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:43:45 by edurance          #+#    #+#             */
/*   Updated: 2025/09/04 15:17:52 by edurance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_built_in.h"

/*built in pwd*/
int	ft_pwd(t_minishell *shell)
{
	ft_printf("%s\n", shell->pwd);
	shell->exit_status = 0;
	return (1);
}
