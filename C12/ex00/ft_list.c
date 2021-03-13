#include "ft_list.h"
#include <stdio.h>

t_list *ft_create_elem(void *data)
{
    t_list *elem;

    elem = (t_list *)malloc(sizeof(t_list));
    elem->data = data;
    elem->next = NULL;

    return (elem);
}