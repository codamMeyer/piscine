/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 21:30:32 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/26 21:30:35 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "ft_string.h"
#include "utils.h"

void	parse_line(const char *line, int line_size, char *num, char *trans)
{
	int i;
	int j;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		num[i] = line[i];
		++i;
	}
	num[i] = '\0';
	while (!is_letter(line[i]))
	{
		++i;
	}
	j = 0;
	while (is_letter(line[i]) && i < line_size)
	{
		trans[j] = line[i];
		++i;
		++j;
	}
	trans[j] = '\0';
}
