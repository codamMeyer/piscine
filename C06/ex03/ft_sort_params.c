/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/21 13:45:21 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/21 14:37:39 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while(s1[i] != '\0' && s2[i] != '\0')
    {
        if(s1[i] != s2[i])
        {
            break;
        }
        ++i;
    }
    return ((int)s1[i] > (int)s2[i]);
}

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

void	ft_sort_params(int argc, char **argv)
{
	int i;
	char *temp;
	int swapped;

	swapped = 1;
	while (swapped)
	{
		i = 1;
		swapped = 0;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]))
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] =  temp;
				swapped = 1;
			}
			++i;
		}
	}

}

int		main(int argc, char **argv)
{
	ft_sort_params(argc, argv);
	ft_print_params(argc, argv);
}
