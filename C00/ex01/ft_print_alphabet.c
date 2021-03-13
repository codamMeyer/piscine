/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_alphabet.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 12:58:36 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/18 12:23:04 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char first_letter;
	char last_letter;

	first_letter = 'a';
	last_letter = 'z';
	while (first_letter <= last_letter)
	{
		write(1, &first_letter, 1);
		++first_letter;
	}
}
