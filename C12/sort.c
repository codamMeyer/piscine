#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int order(int a, int b)
{
    return (a < b);
}

t_list *ft_sort_list(t_list *list, int length, int (*cmp)(int, int))
{
    int swapped;
    int i;
    t_list *cur;
    int *temp;

    swapped = 1;
    while (swapped)
    {
        i = 0;
        swapped = 0;
        cur = list;
        while (i < length - 1)
        {
            if (cmp(*((int *)cur->next->data), *((int *)cur->data)))
            {
                temp = (int *)cur->data;
                cur->data = cur->next->data;
                cur->next->data = temp;
                swapped = 1;
            }
            cur = cur->next;
            ++i;
        }
    }
    return (list);
}

void free_list(t_list *head)
{
    if (head->next != NULL)
    {
        free_list(head->next);
    }
    free(head);
}

int main()
{
    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    int fourtyTwo = 42;

    t_list *elem1 = ft_create_elem(&three);
    t_list *elem2 = ft_create_elem(&one);
    t_list *elem3 = ft_create_elem(&two);
    t_list *elem4 = ft_create_elem(&fourtyTwo);
    t_list *elem5 = ft_create_elem(&four);
    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;
    elem4->next = elem5;

    t_list *next = ft_sort_list(elem1, 5, &order);
    while (next != NULL)
    {
        printf("%d\n", *((int *)(next->data)));
        next = next->next;
    }
    free_list(elem1);
}