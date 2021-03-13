/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocator.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:25:31 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 15:25:33 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_H
# define ALLOCATOR_H
# include "utils.h"

t_map	allocate_map(t_map_info *info);
void	free_map(t_map map, int num_lines);

#endif
