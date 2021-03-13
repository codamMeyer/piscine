/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/12 12:34:09 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/14 10:47:19 by monique          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int main()
{
    ft_putstr(NULL);

    ft_putstr("a");

    ft_putstr("abcdef");
}

