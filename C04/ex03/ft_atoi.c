/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 17:59:46 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/24 17:21:25 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char a)
{
	if (a == ' ' || a == '\f' || a == '\n')
		return (1);
	if (a == '\r' || a == '\t' || a == '\v')
		return (1);
	return (0);
}

int		find_first_number(char *str, int *sign)
{
	int i;

	i = 0;
	while (is_space(str[i]))
	{
		++i;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			*sign *= -1;
		}
		++i;
	}
	return (i);
}

int		ft_atoi(char *str)
{
	int sign;
	int index;
	int result;
	int cur;

	result = 0;
	sign = 1;
	index = find_first_number(str, &sign);
	while (str[index] != '\0')
	{
		cur = (int)str[index];
		if (cur >= '0' && cur <= '9')
		{
			result = (cur - '0') + (result * 10);
		}
		else
		{
			break ;
		}
		++index;
	}
	return (result * sign);
}
