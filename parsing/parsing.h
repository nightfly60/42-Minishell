/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:22:39 by edurance          #+#    #+#             */
/*   Updated: 2025/08/14 17:08:52 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minishell.h"

/*utils prototypes*/
int		is_even(int n);

/*parsing prototypes*/
int		quotes_checker(char *line);

/*	tokenize	*/
int		is_operator(char *s);
int		is_quote(char *s);
int		count_tokens(char *s);
char	**get_tokens(char *line);

#endif