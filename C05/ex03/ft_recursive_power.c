#include <assert.h>

int ft_recursive_power(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  return (nb * ft_recursive_power(nb, (power-1)));
}

int main()
{
  assert(ft_recursive_power(0,0) == 1);
  assert(ft_recursive_power(-5,3) == -125);
  assert(ft_recursive_power(1,0) == 1);
  assert(ft_recursive_power(1,1) == 1);
  assert(ft_recursive_power(3,0) == 1);
  assert(ft_recursive_power(8,0) == 1);
  assert(ft_recursive_power(2,2) == 4);
}
