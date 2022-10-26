/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:13:34 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/27 16:51:58 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_args
{
	char			type;
	int				format_len;
	char			ch;
	int				nb;
	char			*str;
	void			*hex_ptr;
	unsigned int	unsigint;
}					t_args;

// Part 1 functions

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char const *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);

//Part 2 functions

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_itoa_base(unsigned long int nb, char *base);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

// Get next line

char	*get_next_line(int fd);
char	*ft_realloc(char *str, size_t size);

// Ft_printf

int		ft_printf(int fd, const char *format, ...);
int		hex_conversion(int fd, unsigned int nb, char type);
int		int_conversion(int fd, int nb);
int		unsigint_conversion(int fd, unsigned int nb);
int		str_conversion(int fd, char *str);
int		ptr_conversion(int fd, void *ptr);

#endif
