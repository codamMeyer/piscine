/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/10 17:32:26 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/15 21:37:03 by monique          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize_max_numbers(int *array_to_initialize, int index, int value)
{
	while (index >= 0)
	{
		array_to_initialize[index] = value;
		--index;
		--value;
	}
}

void	initialize_numbers_to_print(char *array_to_initialize, int last_digit)
{
	int i;

	i = 0;
	while (i <= last_digit)
	{
		array_to_initialize[i] = 0;
		++i;
	}
}

void	print_numbers(char *numbers, int size)
{
	int i;
	char value;

	i = 0;
	while (i < size)
	{
		value = numbers[i] + '0';
		write(1, &value, 1);
		++i;
	}
}

void    print_size_one()
{
	char digit;
    
    digit = '1';
    while (digit <= '9')
    {
        write(1, &digit, 1);
        if (digit != '9')
        {
            write(1, ", ", 2);
        }
        ++digit;
    }
}

void update_numbers(char * numbers_to_print, int last_index, int current_index)
{
    numbers_to_print[current_index] = numbers_to_print[current_index-1] + 1;
    if(numbers_to_print[current_index] > 9)
    {
        numbers_to_print[current_index] = 0;
    }

    if(current_index < last_index)
    {
        update_numbers(numbers_to_print, last_index, current_index + 1);
    }
}

void	ft_print_combn(int n)
{
	int max_each_number[10];
	char numbers_to_print[10];
	int max_number;
	int last_digit;
	int j;

	max_number = 9;
	last_digit = n - 1;

	initialize_max_numbers(max_each_number, last_digit, max_number);
	initialize_numbers_to_print(numbers_to_print, last_digit);
	
	while (1)
	{
        if(numbers_to_print[last_digit] < max_each_number[last_digit])
        {
            ++numbers_to_print[last_digit];
        }

        print_numbers(numbers_to_print, n);
        write(1, ", ", 2);

        if (numbers_to_print[0] == max_each_number[0])
		{
			print_numbers(numbers_to_print, n);
			break;
		}

        j = 0;
        while(j <= last_digit)
        {
            if (numbers_to_print[j] == max_each_number[j])
            {
                ++numbers_to_print[j-1];
                update_numbers(numbers_to_print, last_digit, j);

                print_numbers(numbers_to_print, n);
                write(1, ", ", 2);
                break;
            }
            ++j;
        }
	}
}


int main()
{
	ft_print_combn(9);
    write(1, "\n",1);
}
