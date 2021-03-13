/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/21 16:50:47 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/22 22:28:07 by monique          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int *ft_range(int min, int max)
{
	int i;
	int *arr;
	const int size = (max - min);
	if (min >= max)
	{	
		return (NULL);
	}
	
	arr = (int *)malloc(size * sizeof(int));
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		++min;
		++i;
	}
	return (arr);
}

int main()
{
    assert(ft_range(3, 2) == NULL);

	int *arr;
	int i = 0; 
	arr = ft_range(-3, 2);
	
	while (i < 5)
	{
		printf("%d ", arr[i]);
		++i;
	}
	printf("\n");

	free(arr);
}
