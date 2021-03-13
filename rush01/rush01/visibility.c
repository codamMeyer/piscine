/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visibility.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/19 18:49:46 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/19 18:50:15 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "visibility.h"

int		check_vis_col_down(t_board board, int col)
{
	const int	target = board[0][col];
	int			visibility;
	int			current;
	int			i;

	i = 1;
	visibility = 1;
	current = board[i][col];
	++i;
	while (i < 5)
	{
		if (board[i][col] > current)
		{
			++visibility;
			current = board[i][col];
		}
		++i;
	}
	return (visibility == target);
}

int		check_vis_col_up(t_board board, int col)
{
	const int	target = board[5][col];
	int			visibility;
	int			current;
	int			i;

	visibility = 1;
	i = 4;
	current = board[i][col];
	--i;
	while (i > 0)
	{
		if (board[i][col] > current)
		{
			++visibility;
			current = board[i][col];
		}
		--i;
	}
	return (visibility == target);
}

int		check_vis_row_left(t_board board, int row)
{
	const int	target = board[row][0];
	int			visibility;
	int			current;
	int			i;

	i = 1;
	visibility = 1;
	current = board[row][i];
	++i;
	while (i < 5)
	{
		if (board[row][i] > current)
		{
			++visibility;
			current = board[row][i];
		}
		++i;
	}
	return (visibility == target);
}

int		check_vis_row_right(t_board board, int row)
{
	const int	target = board[row][5];
	int			visibility;
	int			current;
	int			i;

	i = 4;
	visibility = 1;
	current = board[row][i];
	--i;
	while (i > 0)
	{
		if (board[row][i] > current)
		{
			++visibility;
			current = board[row][i];
		}
		--i;
	}
	return (visibility == target);
}

int		is_valid_visibility(t_board board, int row, int col)
{
	int down;
	int up;
	int left;
	int right;

	down = check_vis_col_down(board, col);
	up = check_vis_col_up(board, col);
	left = check_vis_row_left(board, row);
	right = check_vis_row_right(board, row);
	return (down && up && left && right);
}
