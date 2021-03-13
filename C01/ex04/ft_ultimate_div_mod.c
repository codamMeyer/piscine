/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex04.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/12 12:12:44 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/20 19:05:29 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int temp_div;
	int temp_mod;

	temp_div = (*a) / (*b);
	temp_mod = (*a) % (*b);
	*a = temp_div;
	*b = temp_mod;
}
