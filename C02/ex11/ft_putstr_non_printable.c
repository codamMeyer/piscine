/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_non_printable.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/21 14:54:16 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/21 14:58:03 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char non_printable)
{
	int		i;
	char	hex_number[3];
	int		remainder;
	int		number;

	number = non_printable;
	i = 0;
	while (number > 0)
	{
		remainder = number % 16;
		number = number / 16;
		if (remainder < 10)
			hex_number[i] = remainder + '0';
		else
			hex_number[i] = (remainder - 10) + 'a';
		++i;
	}
	--i;
	write(1, "\\0", 2);
	while (i >= 0)
	{
		write(1, &hex_number[i], 1);
		--i;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		first_printable_char;
	char	cur;

	first_printable_char = 32;
	i = 0;
	while (str[i] != '\0')
	{
		cur = str[i];
		if (cur < first_printable_char)
		{
			print_hex(cur);
		}
		else
		{
			write(1, &cur, 1);
		}
		++i;
	}
}
