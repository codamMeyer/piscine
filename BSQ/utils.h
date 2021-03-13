/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 15:30:53 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/29 15:30:57 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define SUCCESS    0
# define INVALID	-1

typedef int		**t_map;

typedef char	t_buffer[12288];

typedef struct	s_index
{
	int line;
	int col;
}				t_index;

typedef struct	s_linecol
{
	int line;
	int col;
}				t_linecol;

typedef struct	s_map_info
{
	int		num_lines;
	int		num_cols;
	char	empty;
	char	obstacle;
	char	full;
}				t_map_info;

int				count_and_check_cols(int fd, t_map_info *info);
int				has_repeated_symbols(t_map_info *info);
int				has_invalid_symbols(t_map_info *info, char *buf, int buf_size);
void			fill_map_line(int *map_line, char *buffer, t_map_info *info);
void			print_solution(t_map solution, t_map_info *info);

#endif
