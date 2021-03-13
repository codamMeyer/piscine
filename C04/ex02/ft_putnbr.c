/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 15:39:13 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/24 16:50:52 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int nb)
{
	char number;

	if (nb / 10 > 0)
	{
		print_number(nb / 10);
	}
	number = nb % 10 + '0';
	write(1, &number, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	print_number(nb);
}
