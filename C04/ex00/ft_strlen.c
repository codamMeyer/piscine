/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/17 16:52:28 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/24 16:47:15 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int	length;

	if (str == 0)
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
