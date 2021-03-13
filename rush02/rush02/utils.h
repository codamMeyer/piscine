/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 21:10:10 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/26 21:10:16 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define INVALID	-1

typedef struct s_trans	t_trans;

struct	s_trans
{
	char number[50];
	char translation[50];
};

int		count_lines(const char *filename);
int		read_line(const int fd, char *buffer);
int		read_file(const char *filename);
void	parse_line(const char *line, int l_size, char *number, char *trans);
char	*get_translation(t_trans *dict, int num_digits, char *digits);
int		is_letter(char symbol);
#endif
