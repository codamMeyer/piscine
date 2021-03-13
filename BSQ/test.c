#include "allocator.h"
#include "ft_string.h"
#include "min.h"
#include "parse.h"
#include "solve.h"
#include "utils.h"

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void
test_read_first_line()
{
  char* filename = "./maps/map";
  int fd = open(filename, O_RDONLY);
  assert(fd != INVALID);
  t_map_info info;
  assert(read_first_line(fd, &info) == SUCCESS);
  assert(info.num_lines == 8);
  assert(info.obstacle == 'o');
  assert(info.full == 'x');
  assert(info.empty == '.');
  close(fd);

  char* filename2 = "./maps/map_repeated_symbols";
  int fd2 = open(filename2, O_RDONLY);
  assert(fd2 != INVALID);
  t_map_info info2;
  assert(read_first_line(fd2, &info2) == INVALID);
  close(fd2);
}

void
test_repeated_symbols()
{
  t_map_info info;

  info.obstacle = 'o';
  info.full = 'x';
  info.empty = '.';

  assert(!has_repeated_symbols(&info));

  info.full = 'o';
  assert(has_repeated_symbols(&info));

  info.full = 'x';
  info.empty = 'o';

  assert(has_repeated_symbols(&info));

  info.full = '.';
  info.empty = '.';

  assert(has_repeated_symbols(&info));
}

void
test_count_and_check_cols()
{
  t_map_info info;

  info.obstacle = 'o';
  info.full = 'x';
  info.empty = '.';

  int fd = open("./maps/map_count_cols", O_RDONLY);
  assert(count_and_check_cols(fd, &info) == SUCCESS);
  assert(info.num_cols == 5);
  close(fd);

  fd = open("./maps/map_wrong_cols", O_RDONLY);
  assert(count_and_check_cols(fd, &info) == INVALID);
  close(fd);

  fd = open("./maps/map_wrong_symbols", O_RDONLY);
  assert(count_and_check_cols(fd, &info) == INVALID);
  close(fd);
}

void
test_has_invalid_symbols()
{
  t_map_info info;
  info.obstacle = 'o';
  info.full = 'x';
  info.empty = '.';
  assert(!has_invalid_symbols(&info, ".......o.", 9));
  assert(has_invalid_symbols(&info, "...x...o.", 9));
  assert(has_invalid_symbols(&info, ".......o1", 9));
}

void
test_read_line_wrong_fd()
{
  assert(read_line(65463, NULL) == INVALID);
}

void
test_read_line()
{
  char* filename = "./maps/map";
  int fd = open(filename, O_RDONLY);
  assert(fd != INVALID);

  t_buffer buffer;
  int bytes_read = read_line(fd, buffer);
  assert(bytes_read == 4);
  assert(strncmp(buffer, "8.ox", 4) == SUCCESS);
  close(fd);
}

void
test_read_line_EOF()
{
  char* filename = "./maps/map2";
  int fd = open(filename, O_RDONLY);
  assert(fd != -1);

  t_buffer buffer;
  int bytes_read = read_line(fd, buffer);
  assert(bytes_read == 4);
  assert(strncmp(buffer, "5.ox", 4) == SUCCESS);
  close(fd);
}

void
test_parse_invalid_map()
{
  int fd = open("./maps/map_repeated_symbols", O_RDONLY);
  assert(parse_map(fd, 5) == NULL);
  close(fd);
}

void
test_parse_valid_map()
{
  int num_cols = 5;
  int fd = open("./maps/map2", O_RDONLY);
  t_map map = parse_map(fd, num_cols);
  assert(map != NULL);

  int buffer[5][5] = { { 0, 1, 1, 1, 1 },
                       { 1, 1, 1, 1, 0 },
                       { 1, 1, 1, 1, 0 },
                       { 1, 1, 1, 1, 1 },
                       { 1, 1, 1, 1, 1 } };

  int i = 0;
  while (i < 5) {
    int j = 0;
    while (j < 5) {
      assert(map[i][j] == buffer[i][j]);
      ++j;
    }
    ++i;
  }

  free_map(map, 5);
  close(fd);
}

void
test_find_min_value()
{
  assert(find_min_value(1, 2, 3) == 1);
  assert(find_min_value(6, 4, 8) == 4);
  assert(find_min_value(5, 3, 1) == 1);
}

void
test_solve()
{
  assert(solve("./maps/map2") == SUCCESS);
}

void  test_atoi()
{
  assert(ft_atoi("12a4.xb") == INVALID);
  assert(ft_atoi("14.xb\n") == 14);
}

int
main()
{
  test_read_first_line();
  test_repeated_symbols();
  test_count_and_check_cols();
  test_read_line_wrong_fd();
  test_read_line();
  test_read_line_EOF();
  test_has_invalid_symbols();
  test_parse_invalid_map();
  test_parse_valid_map();
  test_find_min_value();
  test_solve();
  test_atoi();
}
