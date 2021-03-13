/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translator.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 21:08:48 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/26 21:08:52 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "translator.h"
#include "utils.h"

void	print_units(t_trans *dict, char *digits)
{
	ft_putstr_with_sep(get_translation(dict, 1, digits), " ");
}

void	print_tens(t_trans *dict, char *digits)
{
	const int	num_digits = 2;
	char		num[2];
	char		*trans;

	trans = NULL;
	if (digits[0] == '0')
	{
		print_units(dict, &digits[1]);
		return ;
	}
	trans = get_translation(dict, num_digits, digits);
	if (trans == NULL)
	{
		num[0] = digits[0];
		num[1] = '0';
		ft_putstr_with_sep(get_translation(dict, num_digits, num), "-");
		if (digits[1] != '0')
			print_units(dict, &digits[1]);
	}
	else
		ft_putstr_with_sep(trans, " ");
}

void	print_hundreds(t_trans *dict, int num_digits, char *digits)
{
	char num[4];

	if (num_digits == 0)
		return ;
	else if (num_digits == 1)
		print_units(dict, &digits[0]);
	else if (num_digits == 2)
		print_tens(dict, &digits[0]);
	else if (num_digits == 3)
	{
		if (digits[0] != '0')
		{
			print_units(dict, &digits[0]);
			append_zeros(2, num);
			ft_putstr_with_sep(get_translation(dict, num_digits, num), " ");
		}
		if (ft_strncmp(&digits[1], "00", 2) != 0)
		{
			print_tens(dict, &digits[1]);
		}
	}
}

int		append_zeros(int num_of_zeros, char *number)
{
	int i;

	number[0] = '1';
	i = 1;
	while (i <= num_of_zeros)
	{
		number[i] = '0';
		++i;
	}
	number[i] = '\0';
	return (i);
}

void	print_number(t_trans *dict, int to_visit, char *digits)
{
	char	buffer[100];
	int		to_print;
	int		size;

	while (to_visit > 0)
	{
		if (to_visit <= 3)
		{
			print_hundreds(dict, to_visit, digits);
			break ;
		}
		else
		{
			to_print = to_visit % 3 ? to_visit % 3 : 3;
			print_hundreds(dict, to_print, digits);
			if (ft_strncmp(digits, "000", 3) != 0)
			{
				size = append_zeros(to_visit - to_print, buffer);
				ft_putstr_with_sep(get_translation(dict, size, buffer), " ");
			}
			to_visit -= to_print;
			digits += to_print;
		}
	}
}
