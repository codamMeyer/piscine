/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcapitalize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/15 14:55:34 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/21 14:53:42 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha_or_num(char c)
{
	int is_letter;
	int is_number;

	is_letter = ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
	is_number = (c >= '0' && c <= '9');
	return (is_letter || is_number);
}

char	to_uppercase(char letter)
{
	int offset;

	if (letter >= 'a' && letter <= 'z')
	{
		offset = 32;
		letter -= offset;
	}
	return (letter);
}

char	to_lower(char letter)
{
	int offset;

	if (letter >= 'A' && letter <= 'Z')
	{
		offset = 32;
		letter += offset;
	}
	return (letter);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	if (str == 0)
	{
		return (str);
	}
	str[0] = to_uppercase(str[0]);
	i = 1;
	while (str[i] != '\0')
	{
		if (!is_alpha_or_num(str[i - 1]))
		{
			str[i] = to_uppercase(str[i]);
		}
		else
		{
			str[i] = to_lower(str[i]);
		}
		++i;
	}
	return (str);
}
