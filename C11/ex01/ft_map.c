//Create the function ft_map which, for a given ints array, applies a function on all
//elements of the array (in order) and returns a array of all the return values.
//• This function will be applied following the array’s order.
#include <assert.h>
#include <stdlib.h>

int plus(int a)
{
    return (a + (a + 2));
}

int *ft_map(int *tab, int length, int (*f)(int))
{
    int *arr = (int *)malloc(length * sizeof(int));
    int i;
    i = 0;
    while (i < length)
    {
        arr[i] = f(tab[i]);
        ++i;
    }

    return (arr);
}

int main()
{
    int arr[5] = {5, 6, 2, 12, 36};
    int *result;

    result = ft_map(arr, 5, &plus);

    for (int i = 0; i < 5; ++i)
    {
        assert(result[i] == plus(arr[i]));
    }
    free(result);
}