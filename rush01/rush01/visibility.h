/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visibility.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/19 19:12:01 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/19 19:12:41 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISIBILITY_H
# define VISIBILITY_H
# include "board.h"

int check_vis_col_down(t_board board, int col);
int check_vis_col_up(t_board board, int col);
int check_vis_row_left(t_board board, int row);
int check_vis_row_right(t_board board, int row);
int is_valid_visibility(t_board board, int row, int col);

#endif
