/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/19 18:24:26 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/19 18:29:28 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "solver.h"

int		populate_input_array(int *dest, char *src)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (src[i] != '\0' && j <= 16)
	{
		if (src[i] >= '1' && src[i] <= '4')
		{
			dest[j] = src[i] - '0';
			++j;
		}
		++i;
	}
	if (j != 16)
	{
		return (0);
	}
	return (1);
}

void	populate_row(t_board board, int *src, int row)
{
	int col;
	int i;

	i = 0;
	col = 1;
	while (i <= 4)
	{
		board[row][col] = src[i];
		++col;
		++i;
	}
}

void	populate_col(t_board board, int *src, int col)
{
	int row;
	int i;

	i = 0;
	row = 1;
	while (i <= 4)
	{
		board[row][col] = src[i];
		++row;
		++i;
	}
}

void	populate_extended_board(t_board board, int *src)
{
	const int offset = 4;

	initialize_empty_board(board);
	populate_row(board, src, 0);
	src += offset;
	populate_row(board, src, 5);
	src += offset;
	populate_col(board, src, 0);
	src += offset;
	populate_col(board, src, 5);
}

int		main(int argc, char **argv)
{
	int		solution_found;
	int		input[16];
	t_board	extended_board;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!populate_input_array(input, argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	populate_extended_board(extended_board, input);
	solution_found = 0;
	solve(extended_board, &solution_found, 1, 1);
	if (!solution_found)
	{
		write(1, "Error\n", 6);
	}
}
