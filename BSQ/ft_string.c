/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:28:58 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 15:29:02 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "parse.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(const char *str)
{
	int		i;
	char	cur;

	if (str == 0)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		cur = str[i];
		write(1, &cur, 1);
		++i;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int	length;

	if (str == 0)
		return (0);
	length = 0;
	while (str[length] != '\0')
		++length;
	return (length);
}

int		ft_atoi(char *str)
{
	int		i;
	int		digit;
	char	dest[100];

	if (get_num_lines(dest, str) == NULL)
		return (INVALID);
	i = 0;
	digit = 0;
	while (dest[i] != '\0')
	{
		if (dest[i] >= '0' && dest[i] <= '9')
		{
			digit = (digit * 10) + (dest[i] - '0');
		}
		else
		{
			return (INVALID);
		}
		i++;
	}
	return (digit);
}

void	print_map_line(t_map_info *info, int *line)
{
	int i;

	i = 0;
	while (i < info->num_cols)
	{
		if (line[i] == 0)
			ft_putchar(info->obstacle);
		else if (line[i] == 1)
			ft_putchar(info->empty);
		else
			ft_putchar(info->full);
		++i;
	}
}
