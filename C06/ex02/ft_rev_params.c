/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/21 12:15:57 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/22 22:15:46 by monique          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

void	ft_rev_params(int num, char **params)
{
	int i;

	i = num - 1;
	while (i > 0)
	{
		ft_print_param(params[i]);
	    --i;
	}
}
int		main(int argc, char **argv)
{
	ft_rev_params(argc, argv);
}
