/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   board.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/19 17:53:51 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/19 20:10:50 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"
#include <unistd.h>

void	initialize_empty_board(t_board board)
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			board[i][j] = 0;
			++j;
		}
		++i;
	}
}

void	print_number(int nb)
{
	char number;

	number = nb + '0';
	write(1, &number, 1);
}

void	print_solution(t_board board)
{
	int i;
	int j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			print_number(board[i][j]);
			if (j < 4)
			{
				write(1, " ", 1);
			}
			++j;
		}
		++i;
		write(1, "\n", 1);
	}
}

void	print_board(t_board board)
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			print_number(board[i][j]);
			write(1, " ", 1);
			++j;
		}
		++i;
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}
