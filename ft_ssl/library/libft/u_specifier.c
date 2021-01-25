/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:47:39 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/23 21:44:27 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	u_get_value(va_list *ap, t_store *a)
{
	if (a->l_cnt == 1)
		return ((unsigned long)va_arg(*ap, unsigned long));
	else if (a->l_cnt == 2)
		return ((unsigned long long)va_arg(*ap, unsigned long long));
	else if (a->h_cnt == 1)
		return ((unsigned short)va_arg(*ap, unsigned int));
	else if (a->h_cnt == 2)
		return ((unsigned char)va_arg(*ap, unsigned int));
	else
		return ((unsigned int)va_arg(*ap, unsigned int));
}

int			u_specifier(char *str, va_list *ap, t_store *a, int i)
{
	char		*temp;
	uint64_t	u;
	int			j;

	j = 0;
	u = u_get_value(ap, a);
	temp = long_itoa(u);
	a->len = ft_strlen(temp);
	a->wid = width_handler(a);
	if (str[i + 1] == '-')
		d_minus_print_func(temp, a);
	else if (str[i + 1] == '0')
		d_print_func_zero(temp, a);
	else
		d_print_func(temp, a);
	j = ft_strlen(temp);
	free(temp);
	return (j);
}

void		d_print_func_plus(char *s, t_store *a)
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
	ft_putchar('+');
	if (prec != 0)
		while (++i < prec)
			ft_putchar('0');
	i = -1;
	if (len != 0)
		while (++i < a->len)
			ft_putchar(s[i]);
}

void		d_print_func_zero_noprec(char *s, t_store *a)
{
	int i;
	int len;

	i = -1;
	if (a->prec > a->len)
		a->prec = a->prec - a->len;
	else if (a->len > a->prec)
		a->len = a->len - a->prec;
	if (a->len == a->prec)
		len = a->len;
	if (a->plus == 1)
		ft_putchar('+');
	if (a->wid != 0)
		while (++i < a->wid)
			ft_putchar('0');
	i = -1;
	if (a->prec != 0)
		while (++i < a->prec)
			ft_putchar('0');
	i = -1;
	if (a->len != 0)
		while (++i < a->len)
			ft_putchar(s[i]);
}
