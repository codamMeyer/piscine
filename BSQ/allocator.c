/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocator.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:25:23 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 15:25:25 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"
#include <fcntl.h>
#include <stdlib.h>

t_map	allocate_map(t_map_info *info)
{
	int		i;
	t_map	map;

	map = (t_map)malloc(info->num_lines * sizeof(int *));
	i = 0;
	while (i < info->num_lines)
	{
		map[i] = (int *)malloc(info->num_cols * sizeof(int));
		++i;
	}
	return (map);
}

void	free_map(t_map map, int num_lines)
{
	int i;

	i = 0;
	while (i < num_lines)
	{
		free(map[i]);
		++i;
	}
	free(map);
}
