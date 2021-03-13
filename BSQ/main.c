/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:27:19 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 20:10:28 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"
#include "ft_string.h"
#include "parse.h"
#include "solve.h"
#include "utils.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	run_from_stdin(const char *temp_file)
{
	const int	fd = open(temp_file, O_RDWR | O_CREAT, 0777 | O_TRUNC);
	t_buffer	buffer;
	int			num_bytes;

	if (fd == INVALID)
	{
		ft_putstr("map error \n");
		return ;
	}
	while (1)
	{
		num_bytes = read_line(0, buffer);
		buffer[num_bytes] = '\n';
		if (num_bytes == 0)
			break ;
		num_bytes = write(fd, buffer, num_bytes + 1);
		if (num_bytes == INVALID)
		{
			ft_putstr("map error\n");
			return ;
		}
	}
	close(fd);
}

void	run(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		solve(argv[i]);
		ft_putstr("\n");
		++i;
	}
}

int		main(int argc, char **argv)
{
	char	*fake_argv[2];

	fake_argv[0] = "";
	fake_argv[1] = "temp.map";
	if (argc > 1)
	{
		run(argc, argv);
	}
	else
	{
		run_from_stdin(fake_argv[1]);
		run(2, fake_argv);
	}
	return (0);
}
