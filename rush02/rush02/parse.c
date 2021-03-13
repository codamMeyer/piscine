/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 21:05:01 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/26 21:07:18 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <unistd.h>
#include <stdlib.h>

int			parse_input_number(char *number)
{
	int i;

	i = 0;
	while (number[i] != '\0')
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
		++i;
	}
	return (1);
}

t_trans		*parse_dict(const char *filename)
{
	t_trans		*dict;
	char		buffer[1024];
	int			i;
	const int	num_lines = count_lines(filename);
	const int	fd = read_file(filename);
	int			bytes_read;

	dict = NULL;
	if (num_lines == INVALID || fd == INVALID)
		return (NULL);
	dict = (t_trans*)malloc((num_lines + 1) * sizeof(t_trans));
	i = 0;
	while (i < num_lines)
	{
		bytes_read = read_line(fd, buffer);
		if (bytes_read == INVALID)
		{
			return (NULL);
		}
		parse_line(buffer, bytes_read, dict[i].number, dict[i].translation);
		++i;
	}
	dict[i].number[0] = '\0';
	return (dict);
}

t_trans		*parse_input_args(int argc, char **argv)
{
	t_trans *dict;

	dict = NULL;
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!parse_input_number(argv[argc - 1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 3)
		dict = parse_dict(argv[1]);
	if (argc == 2)
		dict = parse_dict("numbers.dict");
	if (dict == NULL)
		write(1, "Dict Error\n", 12);
	return (dict);
}
