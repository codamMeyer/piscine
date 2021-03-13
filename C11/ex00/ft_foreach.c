// Create the function ft_foreach which, for a given ints array, applies a
// function on all elements of the array. This function will be applied
// following the array’s order.

//• For example,
//  the function ft_foreach could be called as follows in order to display all
//    ints of the array : ft_foreach(tab, 1337, &ft_putnbr);

#include <unistd.h>

void print_number(int nb)
{
    char number;

    if (nb / 10 > 0)
    {
        print_number(nb / 10);
    }
    number = nb % 10 + '0';
    write(1, &number, 1);
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (nb < 0)
    {
        write(1, "-", 1);
        nb *= -1;
    }
    print_number(nb);
}

void ft_foreach(int *tab, int length, void (*f)(int))
{
    int i;

    i = 0;
    while (i < length)
    {
        f(tab[i]);
        ++i;
    }
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    ft_foreach(array, 5, &ft_putnbr);
}
