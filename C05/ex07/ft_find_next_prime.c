#include <assert.h>

int ft_is_prime(int nb)
{
    int i;

    if (nb <= 1)
        return (0);
    if(nb <= 3)
        return (1);
    if(nb % 2 == 0)
        return (0);
    i = 3;
    while (i < nb)
    {
        if(nb % i == 0)
            return (0);
        i += 2;
    }
  return (1);
}

int ft_find_next_prime(int nb)
{
  while(!ft_is_prime(nb))
  {
    ++nb;
  }
  return (nb);
};

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

  assert(ft_find_next_prime(-5) == 2);
  assert(ft_find_next_prime(0) == 2);
  assert(ft_find_next_prime(1) == 2);
  assert(ft_find_next_prime(2) == 2);
  assert(ft_find_next_prime(3) == 3);
  assert(ft_find_next_prime(4) == 5);
  assert(ft_find_next_prime(5) == 5);
  assert(ft_find_next_prime(6) == 7);
  assert(ft_find_next_prime(8) == 11);
  assert(ft_find_next_prime(20) == 23);
}
