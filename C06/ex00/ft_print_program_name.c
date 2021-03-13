/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/21 11:30:23 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/27 10:56:32 by monique          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_program_name(char *name)
{
	int i;

	i = 0;
	while (name[i] != '\0')
	{
		write(1, &name[i], 1);
		++i;
	}
    write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
    argc += 1;
	ft_print_program_name(argv[0]);
}

