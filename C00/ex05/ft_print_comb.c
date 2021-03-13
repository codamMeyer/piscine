/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_comb.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 15:54:18 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/17 15:56:04 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(char first, char second, char third)
{
	while (third <= '9')
	{
		write(1, &first, 1);
		write(1, &second, 1);
		write(1, &third, 1);
		third++;
		if (first < '7')
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	char first;
	char second;
	char third;

	first = '0';
	while (first <= '7')
	{
		second = first + 1;
		while (second <= '8')
		{
			third = second + 1;
			ft_print_numbers(first, second, third);
			++second;
			third = second + 1;
		}
		++first;
		second = first + 1;
	}
}
