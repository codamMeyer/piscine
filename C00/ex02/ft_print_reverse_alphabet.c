/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_reverse_alphabet.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 14:31:39 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/09 15:01:39 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char first_letter;
	char last_letter;

	first_letter = 'a';
	last_letter = 'z';
	while (last_letter >= first_letter)
	{
		write(1, &last_letter, 1);
		--last_letter;
	}
}
