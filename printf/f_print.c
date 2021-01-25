/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:36:45 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/27 14:08:28 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			f_print_func(char *s, t_store *a)
{
	int i;
	int len;
	int mid;

	i = -1;
	len = ft_strlen(s);
	if (a->wid > len)
	{
		mid = a->wid - len;
		while (++i < mid)
			ft_putchar(' ');
	}
	i = -1;
	while (s[++i] != '\0')
		ft_putchar(s[i]);
	if (a->prec > 6)
	{
		mid = a->prec;
		while (++i < mid)
			ft_putchar('0');
	}
}

void			f_minus_print_func(char *s, t_store *a)
{
	int i;
	int len;
	int mid;

	i = -1;
	len = ft_strlen(s);
	while (s[++i] != '\0')
		ft_putchar(s[i]);
	if (a->prec > 6)
	{
		mid = a->prec - i;
		while (i++ < mid)
			ft_putchar('0');
	}
	i = -1;
	if (a->wid > len)
	{
		mid = a->wid - len;
		while (++i < mid)
			ft_putchar(' ');
	}
}

long double		big_round_up_check(long double f)
{
	f = f + 0.00000045;
	return (f);
}
