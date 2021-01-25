/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <jinpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:20:06 by jinpark           #+#    #+#             */
/*   Updated: 2019/08/16 14:59:17 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdint.h>
# include "libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define U_MAX 4294967295
# define SPECIFIER "dxXficosup%"
# define MAGIC	0.45
# define JUMP "09.-+hlL"
# define FLAG "-= 0#"
# define OCTET 8
# define HEXA 16

typedef struct	s_colour
{
	char		*colour;
	char		*code;
}				t_colour;

typedef struct	s_store
{
	int			wid;
	int			prec;
	int			len;
	int			l_cnt;
	int			h_cnt;
	int			bl_cnt;
	int			plus;
	int			space;
	int			zero;
	int			f_minus;
}				t_store;

typedef struct	s_dispatch_table
{
	char		specifier;
	int			(*function)();
}				t_dt;

int				main(void);
int				ft_printf(char *str, ...);
int				formatting(char *str, va_list *ap, int i);
int				spe_handler(char *str, t_store *a, va_list *ap, int i);
void			check_ops(t_store *a, char *str, int i);
int				di_specifier(char *str, va_list *ap, t_store *a, int i);
void			d_print_func_zero(char *s, t_store *a);
void			d_print_func_space(char *s, t_store *a);
void			d_minus_print_func(char *s, t_store *a);
void			d_print_func(char *s, t_store *a);
void			d_print_func_plus(char *s, t_store *a);
void			d_print_func_zero_noprec(char *s, t_store *a);
void			di_print_combo(char *str, char *stc, int i, t_store *a);
int				s_specifier(char *str, va_list *ap, t_store *a, int i);
int				c_specifier(char *str, va_list *ap, t_store *a, int i);
int				f_specifier(char *str, va_list *ap, t_store *a, int i);
char			*ftoa(double n, t_store *a);
char			*ft_ftoa_f(unsigned long n);
void			f_print_func(char *s, t_store *a);
void			f_minus_print_func(char *s, t_store *a);
int				u_specifier(char *str, va_list *ap, t_store *a, int i);
int				o_specifier(char *str, va_list *ap, t_store *a, int i);
void			o_print_func_hash(char *s, t_store *a);
int				x_specifier(char *str, va_list *ap, t_store *a, int i);
int				bx_specifier(char *str, va_list *ap, t_store *a, int i);
void			d_print_func_hash(char *s, t_store *a);
int				p_specifier(char *str, va_list *ap, t_store *a, int i);
int				percent_sp(char *str, va_list*ap, t_store *a, int i);
void			percent_print(t_store *a);
void			percent_minus_print(t_store *a);
int				op_get_wid(char *str, int i);
int				op_get_prec(char *str, int i);
int				f_op_get_prec(char *str, int i);
int				op_get_plus(char *str, int i);
int				op_get_space(char *str, int i);
int				op_get_zero(char *str, int i);
int				width_handler(t_store *a);
int				get_len(int64_t n);
int				f_get_len(double n);
int				get_len_base(uint64_t num, int base);
int				l_check(char *str, int n, char c);
int				h_check(char *str, int n, char c);
int				res_handler(t_store *a);
char			find_conv(char *str, int n);
char			*long_itoa(int64_t di);
char			*f_long_itoa(int64_t di);
char			*ld_long_itoa(int64_t di);
char			*itoa_base(uint32_t di, int base);
char			*big_itoa_base(uint32_t di, int base);
double			round_up_check(double f);
double			ft_power(int n, int p);
long double		f_get_value(va_list *ap, t_store *a);
int64_t			change_num(int64_t num, int i);
int64_t			di_get_value(va_list *ap, t_store *a);
uint64_t		u_get_value(va_list *ap, t_store *a);
char			*f_ipart(int64_t ipart, t_store *a);
char			*p_itoa_base(uint64_t di, int base);
char			*set_minuszero(char *new, char c);
int				bl_check(char *str, int n, char c);
char			*b_ftoa(long double n, t_store *a);
long double		big_round_up_check(long double f);
char			*bf_handler(char *str, long double bf, t_store *a, int n);
char			*f_handler(char *str, long double f, t_store *a, int n);
void			d_print_func_bhash(char *s, t_store *a);
int				colour_print(char *s, int res);
void			percent_zero_print(t_store *a);

#endif
