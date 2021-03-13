#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "parse.h"
#include "translator.h"

void    test_read_line_wrong_fd()
{
    assert(read_line(65463, NULL) == -1);
}

void    test_count_lines()
{
    assert(count_lines("numbers.dict") == 41);
}

void    test_read_line()
{
    const char *filename = "numbers.dict";
    int fd = open(filename, O_RDONLY);
    assert(fd != -1);

    char buffer[1024];
    const int bytes_read = read_line(fd, buffer);
    assert(bytes_read == 7);
    assert(strncmp(buffer, "0: zero", 7) == 0);
    close(fd);
}

void    test_read_line_EOF()
{
    const char *filename = "test.dict";
    int fd = open(filename, O_RDONLY);
    assert(fd != -1);

    char buffer[1024];
    const int bytes_read = read_line(fd, buffer);
    assert(bytes_read == 6);
    assert(strncmp(buffer, "1: one", 6) == 0);
    close(fd);
}


void    test_parse_inpt_args()
{
    assert(!parse_input_args(1, NULL));
    assert(!parse_input_args(4, NULL));
}

void    test_parse_input_number()
{
    assert(parse_input_number("5"));
    assert(!parse_input_number("-5"));
    assert(!parse_input_number("14dd"));
    assert(!parse_input_number("12,52"));
    assert(!parse_input_number("12.52"));
}

void    test_parse_line()
{
    char number[100];
    char translation[100];
    parse_line("0   :   zerohuh", 12, number, translation);
    assert(strcmp(number,"0") == 0);
    assert(strcmp(translation,"zero") == 0);
}

void    test_parse_line_2()
{
    char number[100];
    char translation[100];
    parse_line("1000:thousand", 13, number, translation);
    assert(strcmp(number,"1000") == 0);
    assert(strcmp(translation,"thousand") == 0);
}

void    test_dict()
{
    t_trans *dict = parse_dict("test.dict");
    assert(dict != NULL);
    assert(strcmp(dict[0].number, "1") == 0);
    assert(strcmp(dict[0].translation, "one") == 0);

    free(dict);
}

void    test_dict2()
{
    t_trans *dict = parse_dict("numbers.dict");
    assert(dict != NULL);
    assert(strcmp(dict[0].number, "0") == 0);
    assert(strcmp(dict[0].translation, "zero") == 0);
    assert(strcmp(dict[40].number, "1000000000000000000000000000000000000") == 0);
    assert(strcmp(dict[40].translation, "undecillion") == 0);

    free(dict);
}

void test_get_translation()
{
    t_trans *dict = parse_dict("numbers.dict");
    assert(dict != NULL);
    const char *trans = get_translation(dict, 2, "90");
    assert(strcmp(trans, "ninety") == 0);
    free(dict);
}

void test_get_translation_not_found()
{
    t_trans *dict = parse_dict("numbers.dict");
    assert(dict != NULL);
    const char *trans = get_translation(dict, 3, "300");
    assert(trans == NULL);
    free(dict);
}

void test_print_hundreds()
{
    printf("--------test print hundreds \n");
    t_trans *dict = parse_dict("numbers.dict");
    assert(dict != NULL);
    print_hundreds(dict, 1, "9");
    printf("\n");
    print_hundreds(dict, 2, "13");
    printf("\n");
    print_hundreds(dict, 2, "40");
    printf("\n");
    print_hundreds(dict, 2, "25");
    printf("\n");
    print_hundreds(dict, 2, "98");
    printf("\n");
    print_hundreds(dict, 3, "123");
    printf("\n");
    print_hundreds(dict, 3, "209");
    printf("\n");
    print_hundreds(dict, 3, "315");
    printf("\n");
    print_hundreds(dict, 3, "948");
    printf("\n");
    print_hundreds(dict, 3, "900");
    printf("\n");
    free(dict);
}

void test_print_number()
{
    printf("------------test print number \n");
    t_trans *dict = parse_dict("numbers.dict");
    assert(dict != NULL);

    printf("948: \n");
    print_number(dict, 3, "948");
    printf("\n");

    printf("1948: \n");
    print_number(dict, 4, "1948");
    printf("\n");

    printf("1000: \n");
    print_number(dict, 4, "1000");
    printf("\n");

    printf("1800: \n");
    print_number(dict, 4, "1800");
    printf("\n");

    printf("150000: \n");
    print_number(dict, 6, "150000");
    printf("\n");

    printf("958450: \n");
    print_number(dict, 6, "958450");
    printf("\n");

    printf("8000: \n");
    print_number(dict, 4, "8000");
    printf("\n");

    printf("1000000: \n");
    print_number(dict, 7, "1000000");
    printf("\n");

    printf("42801050: \n");
    print_number(dict, 8, "42801050");
    printf("\n");

    printf("1000050: \n");
    print_number(dict, 7, "1000050");
    printf("\n");

    printf("1050050: \n");
    print_number(dict, 7, "1050050");
    printf("\n");

    printf("1001100: \n");
    print_number(dict, 7, "1001100");
    printf("\n");

    printf("3000000050: \n");
    print_number(dict, 10, "3000000050");
    printf("\n");



    free(dict);
}


int     main()
{
    test_read_line_wrong_fd();
    test_count_lines();
    test_read_line();
    test_read_line_EOF();
    test_parse_inpt_args();
    test_parse_input_number();
    test_parse_line();
    test_parse_line_2();
    test_dict();
    test_dict2();
    test_get_translation();
    test_get_translation_not_found();
    test_print_hundreds();
    test_print_number();
}

