#include <assert.h>

int ft_fibonacci(int index)
{
 if (index < 0)
   return (-1);
 if (index <= 1)
   return index;
 return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int main()
{
  assert(ft_fibonacci(0) == 0);
  assert(ft_fibonacci(1) == 1);
  assert(ft_fibonacci(2) == 1);
  assert(ft_fibonacci(3) == 2);
}
    

