//Create the function ft_create_elem which creates a new element
//of t_list type.
//It should assign data to the given argument and next to NULL.
#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list *ft_create_elem(void *data)
{
    t_list *elem;

    elem = (t_list *)malloc(sizeof(t_list));
    elem->data = data;
    elem->next = NULL;

    return (elem);
}

int main()
{
    char *mydata = "fuckit";

    t_list *elem = ft_create_elem(mydata);
    printf("%s\n", (char *)elem->data);
    free(elem);
}