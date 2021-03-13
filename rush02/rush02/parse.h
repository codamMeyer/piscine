/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 17:53:42 by bmajor        #+#    #+#                 */
/*   Updated: 2020/07/26 23:35:50 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "utils.h"

int			parse_input_number(char *number);
t_trans		*parse_input_args(int argc, char **argv);
t_trans		*parse_dict(const char *filename);

#endif
