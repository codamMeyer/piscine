/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/23 11:48:52 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/23 15:37:25 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
		++i;
	}
	return ((unsigned char)s2[i] - (unsigned char)'\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	if (str == 0)
		return (0);
	if (to_find == 0)
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (ft_strcmp(&str[i], to_find) == 0)
			{
				return (&str[i]);
			}
		}
		++i;
	}
	return (NULL);
}
