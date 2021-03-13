/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/23 11:46:54 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/23 15:30:54 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int	length;

	if (str == NULL)
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				last_digit;
	unsigned int	i;

	last_digit = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[last_digit] = src[i];
		++i;
		++last_digit;
	}
	dest[last_digit] = '\0';
	return (dest);
}
