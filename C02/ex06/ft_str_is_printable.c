/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_printable.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:44:57 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/15 18:44:40 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		is_printable(char symbol)
{
	char first_printable;
	char last_printable;

	first_printable = 32;
	last_printable = 127;
	return (symbol >= first_printable && symbol <= last_printable);
}

int		ft_str_is_printable(char *str)
{
	int i;

	if (str == 0)
	{
		return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_printable(str[i]))
		{
			return (0);
		}
		++i;
	}
	return (1);
}
