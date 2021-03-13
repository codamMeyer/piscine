#include <assert.h>

int ft_is_prime(int nb)
{
    int i;
    if (nb <= 1)
        return (0);
    if (nb <= 3)
        return (1);
    if (nb % 2 == 0)
        return (0);
    i = 3;
    while (i < nb)
    {
        if((nb % i) == 0)
        {
            return (0);
        }
        i += 2;
    }
    return (1);
}
int main()
{
  assert(ft_is_prime(0) == 0);
  assert(ft_is_prime(1) == 0);
  assert(ft_is_prime(2) == 1);
  assert(ft_is_prime(3) == 1);
  assert(ft_is_prime(4) == 0);
  assert(ft_is_prime(5) == 1);
  assert(ft_is_prime(9) == 0);
  assert(ft_is_prime(100) == 0);
  assert(ft_is_prime(1000000001) == 0);
}

