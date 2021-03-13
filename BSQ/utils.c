/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:30:48 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 15:30:56 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "utils.h"
#include "parse.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		count_and_check_cols(int fd, t_map_info *info)
{
	t_buffer	buffer;
	int			num_cols;
	int			count;

	num_cols = read_line(fd, buffer);
	while (1)
	{
		count = read_line(fd, buffer);
		if (count == 0)
			break ;
		if (count != num_cols || has_invalid_symbols(info, buffer, count))
			return (INVALID);
	}
	info->num_cols = num_cols;
	return (SUCCESS);
}

int		has_repeated_symbols(t_map_info *info)
{
	return ((info->full == info->obstacle) || (info->full == info->empty) ||
		(info->obstacle == info->empty));
}

int		has_invalid_symbols(t_map_info *info, char *buffer, int buffer_size)
{
	int i;

	i = 0;
	while (i < buffer_size)
	{
		if ((buffer[i] != info->obstacle) && (buffer[i] != info->empty))
		{
			return (INVALID);
		}
		++i;
	}
	return (SUCCESS);
}

void	fill_map_line(int *map_line, char *buffer, t_map_info *info)
{
	int i;

	i = 0;
	while (i < info->num_cols)
	{
		if (buffer[i] == info->empty)
			map_line[i] = 1;
		else
			map_line[i] = 0;
		++i;
	}
}

void	print_solution(t_map solution, t_map_info *info)
{
	int i;

	i = 0;
	while (i < info->num_lines)
	{
		print_map_line(info, solution[i]);
		++i;
		ft_putstr("\n");
	}
}
