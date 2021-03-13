/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/21 15:38:26 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/22 22:21:18 by monique          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	if (src == 0 || dest == 0)
	{
		return (dest);
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

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

char *ft_strdup(char *src)
{
	char *cpy;
	int length;
	length = ft_strlen(src);
	cpy = (char *)malloc(length);
	ft_strcpy(cpy, src);
	return (cpy);
}

int main()
{
    char *arr = "hellooooooo!";
    
    char *arr2 = ft_strdup(arr);
    
    assert(strcmp(arr2, arr) == 0);

    free(arr2);
}
