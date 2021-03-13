/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 15:46:54 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/24 17:13:07 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_repeated(char *base, char a, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (base[i] == a)
		{
			return (1);
		}
		++i;
	}
	return (0);
}

int		is_correct_input(char *src, int *base_size)
{
	char	base[100];
	int		i;

	if (src == 0)
	{
		return (0);
	}
	i = 0;
	while (src[i] != '\0')
	{
		if (is_repeated(base, src[i], i) || src[i] == '-' || src[i] == '+')
		{
			return (0);
		}
		base[i] = src[i];
		++i;
	}
	if (i < 2)
	{
		return (0);
	}
	*base_size = i;
	return (1);
}

void	print_number(long long int nbr, int base_size, char *base)
{
	long long int	remainder;
	long long int	result;
	char			numbers_to_print[100];
	int				i;

	i = 0;
	result = nbr;
	while (result > 0)
	{
		remainder = result % base_size;
		result = result / base_size;
		numbers_to_print[i] = base[remainder];
		++i;
	}
	--i;
	while (i >= 0)
	{
		write(1, &numbers_to_print[i], 1);
		--i;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_size;
	long long int	number;

	number = nbr;
	if (!is_correct_input(base, &base_size))
	{
		return ;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		number *= -1;
	}
	print_number(number, base_size, base);
}
