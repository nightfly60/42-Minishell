/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:47:38 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/09/05 14:12:43 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

/*	ouvre le fichier 'name' selon le type:
	- "infile", "outfile", "append".	*/
int	open_files(char *name, t_redirtype type)
{
	int	fd;

	fd = -1;
	if (type == OUTFILE)
		fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	else if (type == INFILE)
		fd = open(name, O_RDONLY);
	else if (type == APPEND)
		fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0666);
	else
		ft_putstr_fd("ERROR: OPEN", STDERR_FILENO);
	if (fd == -1)
		perror(name);
	return (fd);
}
