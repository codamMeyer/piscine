/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 21:09:56 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/26 21:16:55 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_string.h"
#include "utils.h"

int		count_lines(const char *filename)
{
	const int		fd = read_file(filename);
	int				num_lines;
	char			buffer;
	int				bytes_read;

	num_lines = 0;
	while (1)
	{
		bytes_read = read(fd, &buffer, 1);
		if (bytes_read == INVALID)
		{
			close(fd);
			return (INVALID);
		}
		if (bytes_read == 0)
		{
			break ;
		}
		if (buffer == '\n')
		{
			++num_lines;
		}
	}
	close(fd);
	return (num_lines);
}

int		read_line(const int fd, char *buffer)
{
	int i;
	int bytes_read;

	i = 0;
	while (1)
	{
		bytes_read = read(fd, &buffer[i], 1);
		if (bytes_read == INVALID)
		{
			return (INVALID);
		}
		if (buffer[i] == '\n' || bytes_read == 0)
		{
			break ;
		}
		++i;
	}
	return (i);
}

int		read_file(const char *filename)
{
	return (open(filename, O_RDONLY));
}

int		is_letter(char symbol)
{
	const int lower = (symbol >= 'a' && symbol <= 'z');
	const int upper = (symbol >= 'A' && symbol <= 'Z');

	return (lower || upper);
}

char	*get_translation(t_trans *dict, int num_digits, char *digits)
{
	int i;

	i = 0;
	while (dict[i].number[0] != '\0')
	{
		if (ft_strncmp(digits, dict[i].number, num_digits) == 0)
			return (dict[i].translation);
		++i;
	}
	return (NULL);
}
