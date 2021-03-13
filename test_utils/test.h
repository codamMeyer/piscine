#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

int compare_int_arrays(int *arr, int *ref, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] != ref[i])
        {
            return 0;
        }
    }
    return 1;
}

