/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_uppercase.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:43:23 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/22 15:42:57 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		is_upper(char letter)
{
	return (letter >= 'A' && letter <= 'Z');
}

int		ft_str_is_uppercase(char *str)
{
	int i;

	if (str == 0)
	{
		return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_upper(str[i]))
		{
			return (0);
		}
		++i;
	}
	return (1);
}
