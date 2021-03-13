/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/19 18:29:35 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/19 18:29:39 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "visibility.h"

int		has_no_repeated_number(t_board board, int row, int col, int num)
{
	int i;

	i = 1;
	while (i < 5)
	{
		if (board[i][col] == num)
		{
			return (0);
		}
		++i;
	}
	i = 1;
	while (i < 5)
	{
		if (board[row][i] == num)
		{
			return (0);
		}
		++i;
	}
	return (1);
}

int		is_valid_solution(t_board board)
{
	int i;
	int j;

	i = 1;
	while (i < 5)
	{
		if (!(check_vis_row_left(board, i) && check_vis_row_right(board, i)))
			return (0);
		++i;
	}
	j = 1;
	while (j < 5)
	{
		if (!(check_vis_col_down(board, j) && check_vis_col_up(board, j)))
			return (0);
		++j;
	}
	return (1);
}

void	solve(t_board board, int *solution_found, int row, int col)
{
	int choice;

	choice = 1;
	while (choice <= 4 && !(*solution_found))
	{
		if (has_no_repeated_number(board, row, col, choice))
		{
			board[row][col] = choice;
			if (row == 4 && col == 4)
			{
				if (is_valid_solution(board))
				{
					print_solution(board);
					*solution_found = 1;
				}
			}
			else if (row < 4)
				solve(board, solution_found, row + 1, col);
			else
				solve(board, solution_found, 1, col + 1);
		}
		++choice;
	}
	board[row][col] = 0;
}
