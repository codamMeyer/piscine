#include <assert.h>

int		ft_iterative_factorial(int nb)
{
	int		result;
    
	if (nb < 0)
		return (0);
	result = 1;
	while (nb > 0)
	{
		result = nb * result;
		nb--;
	}
    printf("\n");
	return (result);
}

int main()
{
    assert(ft_iterative_factorial(-1) == 0);
    assert(ft_iterative_factorial(0) == 1);
    assert(ft_iterative_factorial(1) == 1);
    assert(ft_iterative_factorial(2) == 2);
    assert(ft_iterative_factorial(3) == 6);
    assert(ft_iterative_factorial(4) == 24);
    assert(ft_iterative_factorial(5) == 120);
    assert(ft_iterative_factorial(12) == 479001600);
}
