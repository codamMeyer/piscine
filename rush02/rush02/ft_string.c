/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 21:11:04 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/26 21:11:08 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_putstr(const char *str)
{
	int		i;
	char	cur;

	if (str == 0)
	{
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		cur = str[i];
		write(1, &cur, 1);
		++i;
	}
}

void	ft_putstr_with_sep(const char *str, const char *sep)
{
	ft_putstr(str);
	ft_putstr(sep);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < (n - 1))
	{
		if (s1[i] != s2[i])
			break ;
		++i;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_strlen(const char *str)
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

char	*ft_strcat(char *dest, char *src)
{
	int last_digit;
	int i;

	last_digit = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[last_digit] = src[i];
		++i;
		++last_digit;
	}
	dest[last_digit] = '\0';
	return (dest);
}
