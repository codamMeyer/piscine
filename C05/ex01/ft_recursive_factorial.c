#include <assert.h>

int ft_recursive_factorial(int nb)
{
  if (nb < 0)
  {
    return (0);
  }
  if (nb == 1 || nb == 0)
  {
    return (1);
  }
  return (nb * ft_recursive_factorial(nb - 1)); 
}

int main()
{
    assert(ft_recursive_factorial(-1) == 0);
    assert(ft_recursive_factorial(0) == 1);
    assert(ft_recursive_factorial(1) == 1);
    assert(ft_recursive_factorial(2) == 2);
    assert(ft_recursive_factorial(3) == 6);
    assert(ft_recursive_factorial(4) == 24);
    assert(ft_recursive_factorial(5) == 120);
    assert(ft_recursive_factorial(12) == 479001600);
}

