#include <assert.h>

int ft_sqrt(int nb)
{
    int i;
    int result;

    if (nb <= 0)
        return 0;
    if (nb == 1)
        return (1);
    i = 0;
    result = 1;
    while (result < nb)
    {
        i++;
        result = i * i;
        if(result == nb)
            return (i);
    }
    return (0);
}

void main()
{
  assert(ft_sqrt(0) == 0);
  assert(ft_sqrt(1) == 1);
  assert(ft_sqrt(4) == 2);
  assert(ft_sqrt(9) == 3);
  assert(ft_sqrt(3) == 0);
}

