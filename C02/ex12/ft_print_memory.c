#include <stdio.h>

void print_as_hex(char *data, unsigned int size)
{
    int index;
    int num_chars_per_column;

    index = 0;
    num_chars_per_column = 2;

    while(size > 0)
    {
        printf("%x", data[index]); 
        ++index;
        printf("%x ", data[index]); 
        ++index;

        size -= num_chars_per_column;
    }
}

void print_address(void *address)
{
    unsigned long pointer_address = (unsigned long)address;
    printf("%016lx: ", (unsigned long)address);
    printf("%016lx: ", pointer_address);
}

void print_as_chars(char *data, unsigned int size)
{
    int index;

    index = 0;
    while(size > 0)
    {
        printf("%c", data[index]); 
        ++index;
        size -= 1;
    }
    printf("\n");
}

void *ft_print_memory(void *addr, unsigned int size)
{
    unsigned int num_characters; 

    num_characters = 16;

    while(size > 0)
    {
        if(size < num_characters)
        {
            num_characters = size;
        }
 
        print_address(addr);
        print_as_hex(addr, num_characters);
        print_as_chars(addr, num_characters);

        addr += num_characters;
        size -= num_characters;
   }

    return (addr);
}

int main()
{
    char input[32] = "aaaaaaaabbbbbbbbccccccccdddddddd";
    ft_print_memory(input, 32);
    printf("\n");

    char input1[20] = "abcdeabcdebbbbbaaaaa";
    ft_print_memory(input1, 20);
    printf("\n");

    char input2[4] = "abab";
    ft_print_memory(input2, 4);
    printf("\n");
}
