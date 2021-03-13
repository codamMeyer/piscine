/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_comb.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 18:03:31 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/17 16:02:58 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digits(int number)
{
	char a;
	char b;

	a = number / 10 + '0';
	b = number % 10 + '0';
	write(1, &a, 1);
	write(1, &b, 1);
}

void	print_comb(int left, int right)
{
	print_digits(left);
	write(1, " ", 1);
	print_digits(right);
	if (left < 98)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int left_digits;
	int max_left;
	int right_digits;
	int max_right;

	left_digits = 0;
	right_digits = left_digits + 1;
	max_right = 99;
	max_left = max_right - 1;
	while (left_digits <= max_left)
	{
		while (right_digits <= max_right)
		{
			print_comb(left_digits, right_digits);
			right_digits++;
		}
		left_digits++;
		right_digits = left_digits + 1;
	}
	left_digits++;
}
