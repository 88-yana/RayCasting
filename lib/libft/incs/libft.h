/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyanagim <hyanagim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:49:55 by tmuramat          #+#    #+#             */
/*   Updated: 2023/03/28 10:07:33 by hyanagim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <fcntl.h>

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_vec {
	float	x;
	float	y;
}	t_vec;

typedef struct timespec	t_timespec;

/*** checker functions ***/
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);

/*** convert functions ***/
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);

/*** string functions ***/
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *c);
size_t		ft_strlcpy(char *dst, const char *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
long		ft_strtol_d(const char *nptr, char **endp);
size_t		ft_strcspn(const char *s1, const char *s2);
void		ft_strtoupper(char *str);

/*** memory functions ***/
void		ft_bzero(void *p, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memchr(const void *buff, int ch, size_t n);
int			ft_memcmp(const void *buff1, const void *buff2, size_t n);
void		*ft_memset(void *p, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_matrixlen(char **src);
char		**ft_matrixdup(char **src);
void		ft_free_matrix(char ***src);
void		ft_memswap(void *a, void *b, size_t size);
void		*ft_realloc(void *ptr, size_t size);
void		*ft_xmalloc(size_t size);
int			ft_xopen(const char *filename, int flag);
void		*ft_memcat(const void *buff1, const void *buff2,
				size_t s1, size_t s2);
void		ft_qsort(void *base, size_t n, size_t size,
				int (*cmp)(const void *, const void *));

/*** print functions ***/
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*** list functions ***/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*** math functions ***/
float		ft_deg_to_rad(float deg);
t_vec		ft_add_vec(t_vec v1, t_vec v2);
bool		ft_cmp_vec(t_vec v1, t_vec v2);
float		ft_distance_vec(t_vec v1, t_vec v2);
t_vec		ft_lerp_vec(t_vec v1, t_vec v2, float t);
t_vec		ft_rotate_vec(t_vec v, float rad);
t_vec		ft_mul_vec(t_vec v1, float t);
t_vec		ft_sub_vec(t_vec v1, t_vec v2);
int			ft_abs(int n);
int			ft_max(int a, int b);
size_t		ft_max_s(size_t a, size_t b);
int			ft_min(int a, int b);
int			ft_count_digits(long long int num, int radix);
double		ft_diff_timespec(const t_timespec *t1, const t_timespec *t2);
int			*ft_binary_search(int *arr, size_t size, int value);
int			*ft_upper_bound(int *arr, int n, int x);
int			*ft_lower_bound(int *arr, int n, int x);

#endif