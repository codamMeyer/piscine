/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 19:38:51 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/23 22:30:46 by monique          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include "../ex05/ft_show_tab.h"
#include <stdlib.h>
#include <stdio.h>

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

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	if (src == 0 || dest == 0)
	{
		return (dest);
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_strdup(char *src)
{
	char *cpy;
	int length;
	length = ft_strlen(src);
	cpy = (char *)malloc(length);
	ft_strcpy(cpy, src);
	return (cpy);
}

void populate_struct(t_stock_str *stock, char *str)
{
    stock->size = ft_strlen(str);
    stock->str = ft_strdup(str);    
    stock->copy = ft_strdup(str);    
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{	
	int i;

    t_stock_str *stock = (t_stock_str*) malloc((ac+1) * sizeof(t_stock_str));
    if(stock == NULL)
    {
        return NULL;
    }
	i = 0;
	while (i < ac)
	{
        populate_struct(&stock[i], av[i]);
        ++i;
	}

    stock[i].size = 0;
    stock[i].str = NULL;
    stock[i].copy = NULL;

    return stock;
}

int main(int ac, char** av)
{
    t_stock_str *str = ft_strs_to_tab(ac, av);
    ft_show_tab(str);
    free(str);
    return 0;
}
