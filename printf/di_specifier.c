/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:44:26 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/23 21:44:20 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_minus_print_func(char *s, t_store *a)
{
	int i;
	int prec;
	int len;

	prec = 0;
	if (a->prec > a->len)
		prec = a->prec - a->len;
	else if (a->len > a->prec)
		len = a->len - a->prec;
	if (a->len == a->prec)
		len = a->len;
	i = -1;
	if (a->plus == 1)
		ft_putchar('+');
	if (prec != 0)
		while (++i < prec)
			ft_putchar('0');
	i = -1;
	if (len != 0)
		while (++i < a->len)
			ft_putchar(s[i]);
	i = -1;
	if (a->wid != 0)
		while (++i < a->wid)
			ft_putchar(' ');
}

void	d_print_func(char *s, t_store *a)
{
	int i;
	int prec;
	int len;

	i = -1;
	prec = 0;
	if (a->prec > a->len)
		prec = a->prec - a->len;
	else if (a->len > a->prec)
		len = a->len - a->prec;
	if (a->len == a->prec)
		len = a->len;
	if (a->wid != 0)
		while (++i < a->wid)
			ft_putchar(' ');
	i = -1;
	if (prec != 0)
		while (++i < prec)
			ft_putchar('0');
	i = -1;
	if (len != 0)
		while (++i < a->len)
			ft_putchar(s[i]);
}

void	d_print_func_zero(char *s, t_store *a)
{
	int i;
	int prec;
	int len;

	i = -1;
	prec = 0;
	if (a->prec > a->len)
		prec = a->prec - a->len;
	else if (a->len > a->prec)
		len = a->len - a->prec;
	if (a->len == a->prec)
		len = a->len;
	if (a->wid != 0)
		while (++i < a->wid)
			ft_putchar(' ');
	i = -1;
	if (prec != 0)
		while (++i < prec)
			ft_putchar('0');
	i = -1;
	if (len != 0)
		while (++i < a->len)
			ft_putchar(s[i]);
}

void	d_print_func_space(char *s, t_store *a)
{
	int i;
	int prec;
	int len;

	i = -1;
	prec = 0;
	if (a->prec > a->len)
		prec = a->prec - a->len;
	else if (a->len > a->prec)
		len = a->len - a->prec;
	if (a->len == a->prec)
		len = a->len;
	if (a->wid != 0)
		while (++i < a->wid)
			ft_putchar(' ');
	i = -1;
	if (a->space == 1 && s[0] != '-')
		ft_putchar(' ');
	if (prec != 0)
		while (++i < prec)
			ft_putchar('0');
	i = -1;
	if (len != 0)
		while (++i < a->len)
			ft_putchar(s[i]);
}

int		di_specifier(char *str, va_list *ap, t_store *a, int i)
{
	int64_t	di;
	int		res;
	char	*temp;

	di = di_get_value(ap, a);
	if (a->l_cnt != 0)
		temp = ld_long_itoa(di);
	else
		temp = long_itoa(di);
	a->len = ft_strlen(temp);
	res = res_handler(a);
	a->wid = width_handler(a);
	di_print_combo(str, temp, i, a);
	if (str[i + 1] == '+' && temp[0] == '-')
		res -= 1;
	if (str[i + 1] == ' ' && temp[0] == '-')
		res -= 1;
	free(temp);
	return (res);
}
