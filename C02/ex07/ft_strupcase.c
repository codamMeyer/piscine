/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strupcase.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:50:49 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/22 15:48:45 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		is_lower(char letter)
{
	return (letter >= 'a' && letter <= 'z');
}

char	*ft_strupcase(char *str)
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
		if (is_lower(str[i]))
		{
			str[i] = str[i] - offset;
		}
		i++;
	}
	return (str);
}
