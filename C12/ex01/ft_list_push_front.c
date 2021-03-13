//Create the function ft_list_push_front which adds a new element
//    of type t_list to the beginning of the list.
//• It should assign data to the given argument.
//• If necessary,
//    it’ll update the pointer at the beginning of the list.
//• Here’s how it should be prototyped :
#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *elem;
    elem = ft_create_elem(data);

    elem->next = *begin_list;
    *begin_list = elem;
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
    char *data1 = "data1";
    char *data2 = "data2";
    char *data3 = "data3";

    t_list *elem1 = ft_create_elem(data1);
    t_list *elem2 = ft_create_elem(data2);
    elem1->next = elem2;
    
    ft_list_push_front(&elem1, data3);
    t_list *next = elem1;
    while (next != NULL)
    {
        printf("%s\n", (char *)next->data);
        next = next->next;
    }
    free_list(elem1);
}