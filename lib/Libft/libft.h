/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:29:03 by pmachado          #+#    #+#             */
/*   Updated: 2024/04/29 15:29:03 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPENF_MAX
#  define OPENF_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

/*
** Part 1 - Libc functions
*/

//String Prototypes
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
bool			ft_isint(const char *str);
size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);

//Memory manip.
void			ft_bzero(void *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
void			ft_free_split(char ***split);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(char *s1, char *s2, size_t n);

//Malloc
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);

/*
** Part 2 - Additional functions
*/

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *str, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** Part 3 - ft_printf
*/

int				ft_printf(const char *format, ...);
int				ft_specifiers(char c, va_list args);
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				ft_print_ptr(unsigned long nbr);
int				ft_print_hex(unsigned long nbr, const char c);
unsigned int	ft_nbr_len(unsigned int nbr);
int				ft_utoa(unsigned int nbr);
int				ft_putnbr(int nbr);

/*
** Part 3 - get_next_line
*/
char			*get_next_line(int fd);
char			*ft_read_function(int fd, char *store_data);
char			*ft_extractline(char *store_data);
char			*ft_update_remainder(char *store_data);
char			*ft_strchr(const char *s, int c);
char			*ft_free_data(char *stash, char *buffer);
size_t			ft_strlen(const char *str);

//Linked list struct

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

//BONUS Linked list Prototypes
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif