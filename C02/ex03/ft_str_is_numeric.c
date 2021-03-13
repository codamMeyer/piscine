/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_numeric.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:37:32 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/15 18:39:21 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		is_number(char number)
{
	return (number >= '0' && number <= '9');
}

int		ft_str_is_numeric(char *str)
{
	int i;

	if (str == 0)
	{
		return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_number(str[i]))
		{
			return (0);
		}
		++i;
	}
	return (1);
}
