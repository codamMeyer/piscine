/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmeyer <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 19:20:51 by mmeyer        #+#    #+#                 */
/*   Updated: 2020/07/23 16:34:02 by mmeyer        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>

typedef int t_bool;

# define TRUE 1
# define FALSE 0

# define EVEN_MSG "I have an even number of arguments." 
# define ODD_MSG "I have an odd number of arguments." 
 
# define SUCCESS 0

# define EVEN(x) (((x) % 2) ? (0) : (1))
#endif
