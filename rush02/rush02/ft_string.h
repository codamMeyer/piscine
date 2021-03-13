/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/26 21:11:14 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/26 21:11:48 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <unistd.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	ft_putstr(const char *str);
void	ft_putstr_with_sep(const char *str, const char *sep);
int		ft_strlen(const char *str);
char	*ft_strcat(char *dest, char *src);

#endif
