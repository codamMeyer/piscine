//Create a function ft_any which will return 1 if, passed to the function f,
//at least one element of the array returns something else than 0. Else, it should return 0.
//• This function will be applied following the array’s order.
//• Here’s how the function should be prototyped : int ft_any(char **tab, int (*f)(char *));
//• The array will be delimited with a null pointer.
#include <assert.h>
#include <stdio.h>

int is_lower(char *c)
{
    int i;

    i = 0;
    while (c[i] != '\0')
    {
        if (c[i] >= 'a' && c[i] <= 'z')
            return (1);
        ++i;
    }
    return (0);
}

int ft_any(char **tab, int (*f)(char *))
{
    int i;
    int j;

    i = 0;
    while (tab[i] != NULL)
    {
        if (f(tab[i]))
            return (1);
        ++i;
    }
    return (0);
}

int main()
{
    char *arr[4] = {"HELLO", "WORLD", "hey there", NULL};
    char *arr2[4] = {"HELLO", "WORLD", "HAHAHA", NULL};

    assert(ft_any(arr, &is_lower));
    assert(ft_any(arr2, &is_lower) == 0);
}