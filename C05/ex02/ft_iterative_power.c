#include <assert.h>

int ft_iterative_power(int nb, int power)
{
    int i;
    int result;

    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    i = 1;
    result = nb;
    while (i < power)
    {
        result *= nb;
        ++i;
    }
    return (result);
}
int main()
{
    assert(ft_iterative_power(0,0) == 1);
    assert(ft_iterative_power(-5,3) == -125);
    assert(ft_iterative_power(1,0) == 1);
    assert(ft_iterative_power(1,1) == 1);
    assert(ft_iterative_power(3,0) == 1);
    assert(ft_iterative_power(8,0) == 1);
    assert(ft_iterative_power(2,2) == 4);
}
