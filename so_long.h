/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacsargs <vacsargs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:00:09 by vacsargs          #+#    #+#             */
/*   Updated: 2023/04/25 18:01:41 by vacsargs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_printf(const char *str, ...);
int		ft_cahrs(const char *str);
int		ft_for(va_list args, const char format);
int		ft_printnum(int num);
int		ft_print_hex(unsigned long long nb, const char format);
int		ft_print_point(unsigned long long lu);
int		ft_it(unsigned int num);

#endif
