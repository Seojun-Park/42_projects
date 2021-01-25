/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 21:00:05 by jinpark           #+#    #+#             */
/*   Updated: 2020/01/07 18:21:59 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdarg.h>


# define BUFF_SIZE	42
# define MAX_FD		4864
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define U_MAX 4294967295
# define SPECIFIER "dxXficosup%"
# define MAGIC	0.45
# define JUMP "09.-+hlL"
# define FLAG "-= 0#"
# define OCTET 8
# define HEXA 16

typedef struct		s_colour
{
	char			*colour;
	char			*code;
}					t_colour;

typedef struct		s_store
{
	int				wid;
	int				prec;
	int				len;
	int				l_cnt;
	int				h_cnt;
	int				bl_cnt;
	int				plus;
	int				space;
	int				zero;
	int 			f_minus;
}					t_store;

typedef struct		s_dispatch_table
{
	char			specifier;
	int				(*function)();
}					t_dt;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl_link
{
	char 			*buf;
	int				count;
	int				i;
	int				nl;
	int				fd;
}					t_gnl_link;

int					ft_atoi(const char *str);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putnbr(int nb);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putstr(const char *str);
char				*ft_strcat(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *dest, const char *src, size_t nb);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strchr(const char *s, int c);
char				*ft_strrev(char *str);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *b, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
char				*ft_itoa(int nbr);
char				**ft_strsplit(char const *s, char c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
unsigned int		ft_strcntfirstchar(char *str, const char *charset);
unsigned int		ft_strcntlastchar(char *str, const char *charset);
char				*ft_strtrim(char const *s);
char				**ft_strsplitchrset(char *str, const char *charset);
void				*ft_dup(void const *content, size_t content_size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstaddend(t_list **alst, t_list *new);
int					ft_atoi_base(char *str, char *base);
char				*ft_itoa_base(int value, char *base);
int					ft_iswhitespace(char c);
size_t				ft_countword(char *s, char c);
int					get_next_line(const int fd, char **line);
char				*ft_utoupper(char *s);
int					ft_absolute(int i);
int					ft_printf(char *str, ...);
int					formatting(char *str, va_list *ap, int i);
int					spe_handler(char *str, t_store *a, va_list *ap, int i);
void				check_ops(t_store *a, char *str, int i);
int					di_specifier(char *str, va_list *ap, t_store *a, int i);
void				d_print_func_zero(char *s, t_store *a);
void				d_print_func_space(char *s, t_store *a);
void				d_minus_print_func(char *s, t_store *a);
void				d_print_func(char *s, t_store *a);
void				d_print_func_plus(char *s, t_store *a);
void				d_print_func_zero_noprec(char *s, t_store *a);
void				di_print_combo(char *str, char *stc, int i, t_store *a);
int					s_specifier(char *str, va_list *ap, t_store *a, int i);
int					c_specifier(char *str, va_list *ap, t_store *a, int i);
int					f_specifier(char *str, va_list *ap, t_store *a, int i);
char				*ftoa(double n, t_store *a);
char				*ft_ftoa_f(unsigned long n);
void				f_print_func(char *s, t_store *a);
void				f_minus_print_func(char *s, t_store *a);
int					u_specifier(char *str, va_list *ap, t_store *a, int i);
int					o_specifier(char *str, va_list *ap, t_store *a, int i);
void				o_print_func_hash(char *s, t_store *a);
int					x_specifier(char *str, va_list *ap, t_store *a, int i);
int					bx_specifier(char *str, va_list *ap, t_store *a, int i);
void				d_print_func_hash(char *s, t_store *a);
int					p_specifier(char *str, va_list *ap, t_store *a, int i);
int					percent_sp(char *str, va_list*ap, t_store *a, int i);
void				percent_print(t_store *a);
void				percent_minus_print(t_store *a);
int					op_get_wid(char *str, int i);
int					op_get_prec(char *str, int i);
int					f_op_get_prec(char *str, int i);
int					op_get_plus(char *str, int i);
int					op_get_space(char *str, int i);
int					op_get_zero(char *str, int i);
int					width_handler(t_store *a);
int					fp_get_len(int64_t n);
int					f_get_len(double n);
int					get_len_base(uint64_t num, int base);
int					l_check(char *str, int n, char c);
int					h_check(char *str, int n, char c);
int					res_handler(t_store *a);
char				find_conv(char *str, int n);
char				*long_itoa(int64_t di);
char				*f_long_itoa(int64_t di);
char				*ld_long_itoa(int64_t di);
char				*itoa_base(uint32_t di, int base);
char				*big_itoa_base(uint32_t di, int base);
double				round_up_check(double f);
double				ft_power(int n, int p);
long double			f_get_value(va_list *ap, t_store *a);
int64_t				change_num(int64_t num, int i);
int64_t				di_get_value(va_list *ap, t_store *a);
uint64_t			u_get_value(va_list *ap, t_store *a);
char				*f_ipart(int64_t ipart, t_store *a);
char				*p_itoa_base(uint64_t di, int base);
char				*set_minuszero(char *new, char c);
int					bl_check(char *str, int n, char c);
char				*b_ftoa(long double n, t_store *a);
long double			big_round_up_check(long double f);
char				*bf_handler(char *str, long double bf, t_store *a, int n);
char				*f_handler(char *str, long double f, t_store *a, int n);
void				d_print_func_bhash(char *s, t_store *a);
void				colour_print(char **s, int *res);
int					get_next_line_link(int const fd, char **line);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
char				*ft_strmerge(char *a, char *b);
int					ft_count_if(char **tab, int(*f)(char *));
void				ft_foreach(int *tab, int length, void(*f)(int));
int					*ft_range(int min, int max);

#endif
