/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:30:26 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 15:30:35 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"
#include "ft_string.h"
#include "min.h"
#include "parse.h"
#include "solve.h"
#include "utils.h"
#include <fcntl.h>

void	populate_first_col_and_row(t_map_info *info, t_map map, t_map solution)
{
	int i;

	i = 0;
	while (i < info->num_cols)
	{
		solution[0][i] = map[0][i];
		++i;
	}
	i = 0;
	while (i < info->num_lines)
	{
		solution[i][0] = map[i][0];
		++i;
	}
}

void	update_sol_val(t_map map, t_map sol, t_index *max, t_linecol linecol)
{
	const int left = sol[linecol.line][linecol.col - 1];
	const int diag = sol[linecol.line - 1][linecol.col - 1];
	const int up = sol[linecol.line - 1][linecol.col];

	if (map[linecol.line][linecol.col] == 1)
		sol[linecol.line][linecol.col] = find_min_value(left, diag, up) + 1;
	else
		sol[linecol.line][linecol.col] = 0;
	if (sol[linecol.line][linecol.col] > sol[max->line][max->col])
	{
		max->line = linecol.line;
		max->col = linecol.col;
	}
}

void	fill_biggest_square(t_map input_map, t_map solution, t_index max)
{
	const int	fill_value = 7;
	const int	max_val = solution[max.line][max.col];
	int			i;
	int			j;

	i = max.line - (max_val - 1);
	while (i <= max.line)
	{
		j = max.col - (max_val - 1);
		while (j <= max.col)
		{
			input_map[i][j] = fill_value;
			++j;
		}
		++i;
	}
}

void	solve_map(t_map input_map, t_map_info *info)
{
	t_map		solution;
	t_index		max;
	t_linecol	line_col;

	max.line = 0;
	max.col = 0;
	solution = allocate_map(info);
	populate_first_col_and_row(info, input_map, solution);
	line_col.line = 1;
	while (line_col.line < info->num_lines)
	{
		line_col.col = 1;
		while (line_col.col < info->num_cols)
		{
			update_sol_val(input_map, solution, &max, line_col);
			++line_col.col;
		}
		++line_col.line;
	}
	fill_biggest_square(input_map, solution, max);
	print_solution(input_map, info);
	free_map(solution, info->num_lines);
}

int		solve(char *filename)
{
	t_map_info	info;
	t_map		map;
	int			fd;

	if (parse_info_and_cols(filename, &info) == INVALID)
		return (INVALID);
	fd = open(filename, O_RDONLY);
	if (fd == INVALID)
		return (INVALID);
	map = parse_map(fd, info.num_cols);
	if (map == NULL)
		return (INVALID);
	solve_map(map, &info);
	free_map(map, info.num_lines);
	return (SUCCESS);
}
