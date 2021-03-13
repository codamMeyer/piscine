/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   min.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:27:43 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 15:27:45 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "min.h"

int		find_min_value(int first, int second, int third)
{
	int min;

	min = first;
	if (second < min)
		min = second;
	if (third < min)
		min = third;
	return (min);
}
