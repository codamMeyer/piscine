/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:30:29 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 15:30:30 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H
# include "utils.h"
# include <stdio.h>

void	populate_first_col_and_row(t_map_info *info, t_map map, t_map solution);
void	update_sol_val(t_map map, t_map sol, t_index *max, t_linecol line_col);
void	fill_biggest_square(t_map input_map, t_map solution, t_index max);
void	solve_map(t_map map, t_map_info *info);
int		solve(char *filename);

#endif
