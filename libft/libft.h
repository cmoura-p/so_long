/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:04:20 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/19 21:06:36 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>

# define DEC    "0123456789"
# define HEXL   "0123456789abcdef"
# define HEXU   "0123456789ABCDEF"

// libft
long	ft_atol(const char *s);
void	ft_bzero(void *buff, size_t n);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memset(void *ptr, int value, size_t num);
size_t	ft_strlen(const char *s);

// printf
int		ft_printf(const char *format, ...);
int		ft_check_format(char datatype, va_list ap);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_num(long n, char *base, char datatype);
int		ft_print_ptr(size_t n, char *base);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// get_next_line
char	*get_next_line(int fd);
char	*ft_extract(char *str);
char	*ft_getchr(const char *s, int c);
size_t	ft_getlen(const char *str);
char	*ft_getjoin(char *s1, char *s2);
void	ft_getcpy(char *str);

#endif
