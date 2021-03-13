/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:29:08 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 15:29:13 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include "utils.h"

void	ft_putstr(const char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	print_map_line(t_map_info *info, int *line);

#endif
