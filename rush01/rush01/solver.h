/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/19 18:47:52 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/19 18:47:56 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include "board.h"

int		has_no_repeated_number(t_board board, int row, int col, int num);
int		is_valid_solution(t_board board);
void	solve(t_board board, int *solution_found, int row, int col);

#endif
