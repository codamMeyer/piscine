/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_lowercase.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:41:13 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/15 18:40:27 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		is_lower(char letter)
{
	return (letter >= 'a' && letter <= 'z');
}

int		ft_str_is_lowercase(char *str)
{
	int i;

	if (str == 0)
	{
		return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_lower(str[i]))
		{
			return (0);
		}
		++i;
	}
	return (1);
}
