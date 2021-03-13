/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlowcase.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/15 14:48:17 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/16 10:59:24 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		is_upper(char letter)
{
	return (letter >= 'A' && letter <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	int i;
	int offset;

	if (str == 0)
	{
		return (str);
	}
	i = 0;
	offset = 32;
	while (str[i] != '\0')
	{
		if (is_upper(str[i]))
		{
			str[i] = str[i] + offset;
		}
		i++;
	}
	return (str);
}
