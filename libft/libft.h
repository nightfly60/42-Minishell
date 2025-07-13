/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:15:05 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/07/09 12:40:49 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// libft
long				ft_atoi(const char *nptr);
void				ft_bzero(void *s, unsigned long n);
void				*ft_calloc(unsigned long nmemb, unsigned long size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, unsigned long n);
int					ft_memcmp(const void *s1, const void *s2, unsigned long n);
void				*ft_memcpy(void *dest, const void *src, unsigned long n);
void				*ft_memmove(void *dest, const void *src, unsigned long n);
void				*ft_memset(void *s, int c, unsigned long n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
unsigned long		ft_strlcat(char *dst, const char *src, unsigned long size);
unsigned long		ft_strlcpy(char *dst, const char *src, unsigned long size);
unsigned long		ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, unsigned long n);
char				*ft_strnstr(const char *haystack, const char *needle,
						unsigned long len);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_substr(char const *s, unsigned int start,
						unsigned long len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

// listes chainees
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// ftprintf
int					ft_putstr(char *s);
void				ft_putnbr_unsigned(unsigned long long n, int *add);
void				ft_putnbr(long long n, int *add);
int					ft_putchar(char c);
void				ft_putaddr(void *point, int *add);
void				ft_put_hex(long nbr, int caps, int *add);
int					ft_printf(const char *format, ...);

// gnl
char				*get_next_line(int fd);
int					bn_pos(char *s);
void				mconcat(char ***s, char *buf, int fd);
void				my_read(int fd, char ***rem, int *res);
void				new_remaining(char ***rem, int fd);
char				*get_result(char *s);
void				freeall_gnl(char ***res, int fd);

// others
void				ft_freeall(char **tab);
int					ft_strcmp(const char *s1, const char *s2);
void				print_int_table(int *tab);
void				print_str_table(char **tab);
int					count_elem(void **tab);

#endif
