/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   board.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/19 18:00:33 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/19 18:01:22 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

typedef int	t_board[6][6];
void	print_board(t_board board);
void	print_solution(t_board board);
void	initialize_empty_board(t_board board);
void	print_number(int nb);

#endif
