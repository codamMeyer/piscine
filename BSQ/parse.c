/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:29:53 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 15:29:58 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"
#include "ft_string.h"
#include "parse.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_num_lines(char *dest, char *src)
{
	int i;

	if (ft_strlen(src) < 4)
		return (NULL);
	i = 0;
	while (src[i + 3] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		parse_info_and_cols(char *filename, t_map_info *info)
{
	const int fd = open(filename, O_RDONLY);

	if (fd == INVALID)
	{
		ft_putstr("map error\n");
		return (INVALID);
	}
	if (read_first_line(fd, info) == INVALID)
	{
		ft_putstr("map error\n");
		return (INVALID);
	}
	if (info->num_cols == INVALID || count_and_check_cols(fd, info) == INVALID)
	{
		ft_putstr("map error\n");
		return (INVALID);
	}
	close(fd);
	return (SUCCESS);
}

t_map	parse_map(int fd, int num_cols)
{
	t_map_info	info;
	t_buffer	buffer;
	t_map		map;
	int			i;

	if (read_first_line(fd, &info) == INVALID)
		return (NULL);
	info.num_cols = num_cols;
	map = allocate_map(&info);
	i = 0;
	while (i < info.num_lines)
	{
		read_line(fd, buffer);
		fill_map_line(map[i], buffer, &info);
		++i;
	}
	return (map);
}

int		read_first_line(int fd, t_map_info *info)
{
	int			i;
	int			bytes_read;
	int			last;
	t_buffer	buffer;

	i = 0;
	while (1)
	{
		bytes_read = read(fd, &buffer[i], 1);
		if (bytes_read == INVALID)
			return (INVALID);
		if (buffer[i] == '\n' || bytes_read == 0)
			break ;
		++i;
	}
	last = i - 1;
	info->full = buffer[last];
	info->obstacle = buffer[last - 1];
	info->empty = buffer[last - 2];
	info->num_lines = ft_atoi(buffer);
	if (has_repeated_symbols(info) || info->num_lines == INVALID)
		return (INVALID);
	return (SUCCESS);
}

int		read_line(int fd, char *buffer)
{
	int		i;
	int		bytes_read;
	char	cur;

	i = 0;
	while (1)
	{
		bytes_read = read(fd, &cur, 1);
		if (bytes_read == INVALID)
		{
			return (INVALID);
		}
		if (cur == '\n' || bytes_read == 0)
		{
			break ;
		}
		buffer[i] = cur;
		++i;
	}
	return (i);
}
