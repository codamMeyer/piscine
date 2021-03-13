/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_numbers.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 15:02:15 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/09 15:25:06 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char first_digit;
	char last_digit;

	first_digit = 48;
	last_digit = 57;
	while (first_digit <= last_digit)
	{
		write(1, &first_digit, 1);
		++first_digit;
	}
}
