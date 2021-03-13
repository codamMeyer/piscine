/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:29:56 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 15:30:00 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "utils.h"

char	*get_num_lines(char *dest, char *src);
int		parse_info_and_cols(char *filename, t_map_info *info);
t_map	parse_map(int fd, int num_cols);
int		read_first_line(int fd, t_map_info *info);
int		read_line(int fd, char *buffer);

#endif
