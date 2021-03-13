/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translator.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 21:09:15 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/26 21:09:17 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATOR_H
# define TRANSLATOR_H
# include "utils.h"

void	print_units(t_trans *dict, char *digits);
void	print_tens(t_trans *dict, char *digits);
void	print_hundreds(t_trans *dict, int num_digits, char *digits);
void	print_number(t_trans *dict, int to_visit, char *digits);
int		append_zeros(int num_of_zeros, char *number);

#endif
