/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ex02.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/12 11:59:42 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/20 18:38:19 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
