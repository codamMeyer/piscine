/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 21:09:24 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/26 21:09:30 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "utils.h"
#include "parse.h"
#include "translator.h"

void	run(int argc, char **argv)
{
	t_trans *dict;
	char	*number_to_print;
	int		num_length;

	if (argv[argc - 1][0] == '0' && ft_strlen(argv[argc - 1]) > 1)
	{
		write(1, "Error\n", 6);
		return ;
	}
	dict = NULL;
	number_to_print = NULL;
	dict = parse_input_args(argc, argv);
	if (dict == NULL)
		return ;
	number_to_print = argv[argc - 1];
	num_length = ft_strlen(number_to_print);
	print_number(dict, num_length, number_to_print);
	ft_putstr("\n");
	free(dict);
}

int		main(int argc, char **argv)
{
	run(argc, argv);
}
