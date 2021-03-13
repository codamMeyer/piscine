/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/21 11:38:16 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/21 12:17:18 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_param(char *param)
{
	int i;

	i = 0;
	while (param[i] != '\0')
	{
		write(1, &param[i], 1);
		++i;
	}
	write(1, "\n", 1);
}

void	ft_print_params(int num, char **params)
{
	int i;

	i = 1;
	while (i < num)
	{
		ft_print_param(params[i]);
		++i;
	}
}

int		main(int argc, char **argv)
{
	ft_print_params(argc, argv);	
}
