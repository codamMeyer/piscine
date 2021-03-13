/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 18:19:29 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/23 11:34:18 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../test_utils/test.h"

int		ft_strlen(char *str)
{
	int		length;

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


unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_size;
	unsigned int src_size;
	unsigned int i;
	unsigned int max_to_append;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);

	max_to_append = (size - dest_size - 1);
	i = 0; 
	while (src[i] != '\0' && i < max_to_append)
	{
		dest[dest_size + i] = src[i];
		++i;	
    }

	return (dest_size + src_size);
}

int main()
{
    char dest[20] = "hello \0";
    assert(ft_strlcat(dest, "world!", 20) == 12);

    char dest1[10] = "hello \0";
    assert(ft_strlcat(dest1, "world!", 10) == 12);
}
