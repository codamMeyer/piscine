/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rev_int_tab.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/12 16:31:20 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/17 16:32:21 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		temp = tab[j];
		tab[j] = tab[i];
		tab[i] = temp;
		++i;
		--j;
	}
}
