/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_func6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 22:54:33 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/22 19:58:56 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	o_print_func_hash(char *s, t_store *a)
{
	int i;
	int prec;
	int len;

	i = -1;
	if (a->prec > a->len)
		prec = a->prec - a->len;
	else
		prec = 0;
	if (a->len > a->prec)
		len = a->len - a->prec;
	if (a->wid != 0)
		while (++i < a->wid)
			ft_putchar(' ');
	i = -1;
	ft_putchar('0');
	if (prec != 0)
		while (++i < prec)
			ft_putchar('0');
	i = -1;
	if (len != 0)
		while (++i < a->len)
			ft_putchar(s[i]);
}

int		op_get_space(char *str, int i)
{
	int n;

	n = i + 1;
	if (str[n] == ' ')
		return (1);
	return (0);
}

int		res_handler(t_store *a)
{
	if (a->space == 1 || a->plus == 1)
	{
		if (a->wid > a->prec && a->wid > a->len)
			return (a->wid + 1);
		else if (a->prec > a->wid && a->prec > a->len)
			return (a->prec + 1);
		else if (a->len > a->wid && a->len > a->prec)
			return (a->len + 1);
	}
	else
	{
		if (a->wid > a->prec && a->wid > a->len)
			return (a->wid);
		else if (a->prec > a->wid && a->prec > a->len)
			return (a->prec);
		else if (a->len > a->wid && a->len > a->prec)
			return (a->len);
	}
	return (0);
}

int		op_get_zero(char *str, int i)
{
	int n;

	n = i + 1;
	if (str[n] == '0')
		return (1);
	return (0);
}

void	di_print_combo(char *str, char *src, int i, t_store *a)
{
	if (str[i + 1] == '-')
		d_minus_print_func(src, a);
	else if (str[i + 1] == '0')
	{
		if (a->prec == 0)
			d_print_func_zero_noprec(src, a);
		else
			d_print_func_zero(src, a);
	}
	else if (str[i + 1] == '+' && src[0] != '-')
		d_print_func_plus(src, a);
	else if (str[i + 1] == ' ')
		d_print_func_space(src, a);
	else
		d_print_func(src, a);
}
