/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:34:17 by jbrosio           #+#    #+#             */
/*   Updated: 2025/09/18 18:03:11 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef LONG_LONG_MAX
#  define LONG_LONG_MAX 4147483748
# endif

# ifndef LONG_LONG_MIN
#  define LONG_LONG_MIN -4147483748
# endif

//list
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// mem functions
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);

// str functions
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strrchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);

// verifications functions
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
void		ft_bzero(void *s, size_t n);
char		*ft_itoa(int n);
int			ft_double_sign_error(char *str);

// files descriptor functions
void		ft_putendl_fd(char *s, int fd);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);
int			ft_atoi(const char *nptr);
float		ft_atod(char *nptr);
long int	ft_atol(const char *nptr);

// nodos funcions
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// printf functions
int			ft_printf(char const *s, ...);
int			ft_searchtype(va_list vargs, char c);
int			ft_puthex_mayus(unsigned long long num);
int			ft_puthex_x(unsigned long long num);
int			ft_puthex_p(unsigned long long num);
int			ft_putnbr_u(long int n, int fd);

// gnl functions
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_strdup_gnl(const char *s);
char		*ft_strchr_gnl(const char *s, int c);
size_t		ft_strlen_gnl(char *str);
char		*get_next_line(int fd);
char		*gnl_substr(char *s, unsigned int start, size_t len, size_t i);

#endif
