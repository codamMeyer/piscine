/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_alpha.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 14:14:20 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/15 18:37:45 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char l)
{
	return ((l >= 'A' && l <= 'Z') || (l >= 'a' && l <= 'z'));
}

int		ft_str_is_alpha(char *str)
{
	int i;

	if (str == 0)
	{
		return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_alpha(str[i]))
		{
			return (0);
		}
		++i;
	}
	return (1);
}
