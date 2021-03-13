/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 19:38:51 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/23 22:28:17 by monique          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;
	char	cur;

    if (str == 0)
    {
        return ;
    }

	i = 0;
	while (str[i] != '\0')
	{
		cur = str[i];
		write(1, &cur, 1);
		++i;
	}
}

void ft_putnbr(int nb)
{
    char result;
    
    if (nb / 10 > 0)
    {
        ft_putnbr(nb / 10);
    }
    result = (nb % 10) + '0';
    write(1, &result, 1);
}

void print_struct(t_stock_str *par)
{
    ft_putstr(par->str);
    write(1, "\n", 1);
    ft_putnbr(par->size);
    write(1, "\n", 1);
    ft_putstr(par->copy);
    write(1, "\n", 1);
}

void ft_show_tab(struct s_stock_str *par)
{
    int i;
    if(par == NULL)
    {
        return;
    }
    i = 0;
    while (par[i].str != NULL)
    {
        print_struct(&par[i]);
        ++i;
    }
}

