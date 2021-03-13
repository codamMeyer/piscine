/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_int_tab.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/12 16:37:49 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/20 18:56:16 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int swapped;

	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < size - 1)
		{
			if (tab[i + 1] < tab[i])
			{
				ft_swap(&tab[i + 1], &tab[i]);
				swapped = 1;
			}
			++i;
		}
	}
}
