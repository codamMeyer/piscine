#include "solver.h"
#include "visibility.h"
#include <assert.h>

void test_num_position()
{
    t_board testBoard2 = {{0,4,3,2,1,0},
                                   {4,1,2,0,4,1},
                                   {3,0,0,0,0,2},
                                   {2,0,0,0,0,2},
                                   {1,0,0,0,0,2},
                                   {0,1,2,2,2,0}};
    print_board(testBoard2);
    assert(!has_no_repeated_number(testBoard2, 1, 2, 3));
    assert(!has_no_repeated_number(testBoard2, 1, 2, 4));

    assert(has_no_repeated_number(testBoard2, 2, 1, 3));
    assert(!has_no_repeated_number(testBoard2, 2, 1, 1));

    assert(has_no_repeated_number(testBoard2, 3, 4, 3));
    assert(!has_no_repeated_number(testBoard2, 3, 4, 4));
  
    assert(has_no_repeated_number(testBoard2, 4, 1, 3));
    assert(!has_no_repeated_number(testBoard2, 4, 1, 1));
}

void test_visibility_down()
{
    t_board testBoard = {{0,4,3,2,1,0},
                                  {4,1,2,3,4,1},
                                  {3,2,3,4,1,2},
                                  {2,3,4,1,2,2},
                                  {1,4,1,2,3,2},
                                  {0,1,2,2,2,0}};

    assert(check_vis_col_down(testBoard, 1));
    assert(check_vis_col_down(testBoard, 2));
    assert(check_vis_col_down(testBoard, 3));
    assert(check_vis_col_down(testBoard, 4));
    print_board(testBoard);

    t_board testBoard2 = {{0,4,3,2,1,0},
                                   {4,4,1,4,1,1},
                                   {3,2,4,3,4,2},
                                   {2,3,3,2,3,2},
                                   {1,2,1,1,2,2},
                                   {0,1,2,2,2,0}};

    assert(!check_vis_col_down(testBoard2, 1));
    assert(!check_vis_col_down(testBoard2, 2));
    assert(!check_vis_col_down(testBoard2, 3));
    assert(!check_vis_col_down(testBoard2, 4));
    print_board(testBoard2);
}

void test_visibility_up()
{
    t_board testBoard = {{0,4,3,2,1,0},
                                  {4,1,2,3,4,1},
                                  {3,2,3,4,1,2},
                                  {2,3,4,1,2,2},
                                  {1,4,1,2,3,2},
                                  {0,1,2,2,2,0}};

    assert(check_vis_col_up(testBoard, 1));
    assert(check_vis_col_up(testBoard, 2));
    assert(check_vis_col_up(testBoard, 3));
    assert(check_vis_col_up(testBoard, 4));
    print_board(testBoard);
    
    t_board testBoard2 = {{0,4,3,2,1,0},
                                   {4,4,1,4,1,1},
                                   {3,2,4,3,4,2},
                                   {2,3,3,2,3,2},
                                   {1,2,1,1,2,2},
                                   {0,1,2,2,2,0}};
    
    assert(!check_vis_col_up(testBoard2, 1));
    assert(!check_vis_col_up(testBoard2, 2));
    assert(!check_vis_col_up(testBoard2, 3));
    assert(!check_vis_col_up(testBoard2, 4));
    print_board(testBoard);

}

void test_visibility_left()
{
    t_board testBoard = {{0,4,3,2,1,0},
                                  {4,1,2,3,4,1},
                                  {3,2,3,4,1,2},
                                  {2,3,4,1,2,2},
                                  {1,4,1,2,3,2},
                                  {0,1,2,2,2,0}};

    assert(check_vis_row_left(testBoard, 1));
    assert(check_vis_row_left(testBoard, 2));
    assert(check_vis_row_left(testBoard, 3));
    assert(check_vis_row_left(testBoard, 4));
    print_board(testBoard);

    t_board testBoard2 = {{0,4,3,2,1,0},
                                   {4,1,2,4,1,1},
                                   {3,2,4,3,4,2},
                                   {2,3,3,2,3,2},
                                   {1,2,4,1,2,2},
                                   {0,1,2,2,2,0}};

    assert(!check_vis_row_left(testBoard2, 1));
    assert(!check_vis_row_left(testBoard2, 2));
    assert(!check_vis_row_left(testBoard2, 3));
    assert(!check_vis_row_left(testBoard2, 4));
    print_board(testBoard2);
}

void test_visibility_right()
{
    t_board testBoard = {{0,4,3,2,1,0},
                                  {4,1,2,3,4,1},
                                  {3,2,3,4,1,2},
                                  {2,3,4,1,2,2},
                                  {1,4,1,2,3,2},
                                  {0,1,2,2,2,0}};

    assert(check_vis_row_right(testBoard, 1));
    assert(check_vis_row_right(testBoard, 2));
    assert(check_vis_row_right(testBoard, 3));
    assert(check_vis_row_right(testBoard, 4));
    print_board(testBoard);

    t_board testBoard2 = {{0,4,3,2,1,0},
                                   {4,1,2,4,1,1},
                                   {3,2,4,3,4,2},
                                   {2,3,4,3,2,2},
                                   {1,2,4,3,2,2},
                                   {0,1,2,2,2,0}};

    assert(!check_vis_row_right(testBoard2, 1));
    assert(!check_vis_row_right(testBoard2, 2));
    assert(!check_vis_row_right(testBoard2, 3));
    assert(!check_vis_row_right(testBoard2, 4));
    print_board(testBoard2);
}

void test_visibility_all()
{
    t_board testBoard = {{0,4,3,2,1,0},
                                  {4,1,2,3,4,1},
                                  {3,2,3,4,1,2},
                                  {2,3,4,1,2,2},
                                  {1,4,1,2,3,2},
                                  {0,1,2,2,2,0}};

    assert(is_valid_visibility(testBoard, 2, 2));
    assert(is_valid_visibility(testBoard, 3, 3));
    assert(is_valid_visibility(testBoard, 1, 1));
    assert(is_valid_visibility(testBoard, 4, 4));
    print_board(testBoard);

    t_board testBoard2 = {{0,4,3,2,1,0},
                                   {4,1,1,4,4,1},
                                   {3,2,2,3,4,2},
                                   {2,3,4,3,2,2},
                                   {1,2,1,2,2,2},
                                   {0,1,2,2,2,0}};

    assert(!is_valid_visibility(testBoard2, 1, 1));
    assert(!is_valid_visibility(testBoard2, 4, 4));
    assert(!is_valid_visibility(testBoard2, 3, 3));
    assert(!is_valid_visibility(testBoard2, 2, 2));
    print_board(testBoard2);
}

void test_check_solution()
{
    t_board testBoard = {{0,4,3,2,1,0},
                                  {4,1,2,3,4,1},
                                  {3,2,3,4,1,2},
                                  {2,3,4,1,2,2},
                                  {1,4,1,2,3,2},
                                  {0,1,2,2,2,0}};

    assert(is_valid_solution(testBoard));

    t_board testBoard2 = {{0,4,3,2,1,0},
                                   {4,1,1,4,4,1},
                                   {3,2,2,3,4,2},
                                   {2,3,4,3,2,2},
                                   {1,2,1,2,2,2},
                                   {0,1,2,2,2,0}};

    assert(!is_valid_solution(testBoard2));
}

int main()
{
    test_visibility_down();
    test_visibility_up();
    test_visibility_left();
    test_visibility_right();
    test_visibility_all();
    test_check_solution();
    test_num_position();
}
