/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 13:54:50 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/22 22:42:38 by monique          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	length;

	if (str == 0)
	{
		return (0);
	}
	length = 0;
	while (str[length] != '\0')
	{
		++length;
	}
	return (length);
}

int		length_to_allocate(int size, char **strs, char *sep)
{
	int length;
	int i;

	length = 0;
	i = 0;
	while (i < size)
	{
		length += ft_strlen(strs[i]);
		++i;
	}
	length += ft_strlen(sep) * (size - 1);
	return (length);
}

void	ft_strcpy(char *dest, char *src, int *offset)
{
	int i;

	if (src == 0 || dest == 0)
	{
		return ;
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	*offset += i;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*cat_arr;
	int		cat_size;
	int		i;
	int		offset;

	if (size == 0)
	{
		return (cat_arr = malloc(0));
	}
	cat_size = length_to_allocate(size, strs, sep);
	cat_arr = (char *)malloc(cat_size);
	i = 0;
	offset = 0;
	while (i < size)
	{
		ft_strcpy(&cat_arr[offset], strs[i], &offset);
		if (i < size - 1)
			ft_strcpy(&cat_arr[offset], sep, &offset);
		++i;
	}
	return (cat_arr);
}

int main()
{
	char *strgs[4] = {"aa", "bb", "cc", "gd"};
	char *cat;

	assert(length_to_allocate(4, strgs, ", ") == 14);
	assert(length_to_allocate(4, strgs, " - ") == 17);
	cat = ft_strjoin(4, strgs, ", ");
	printf("%s\n", cat);
    free(cat);

    char *cat2 = ft_strjoin(0, strgs, ",");
    free(cat2);
}
