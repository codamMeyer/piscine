#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{
  const int size = max - min;
  int i = 0;
  if (min >= max)
  {
      *range = NULL;
      return (0);
  }

  *range = (int *)malloc(size * sizeof(int));
  if (*range == NULL)
  {
      return (-1);
  }
  while (min < max)
  {
    range[0][i] = min;
    ++i;
    ++min;
  }
  
  return(size);
}

int main()
{
    int *arr;
    int **pointer_to_arr = &arr;
    int i = 0; 
    int size = ft_ultimate_range(pointer_to_arr, -5, 7);
    while (i < size)
    {
        printf("%d ", pointer_to_arr[0][i]);
        ++i;
    }
    printf("\n");

    free(arr);
}

