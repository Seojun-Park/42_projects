/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <jinpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:29:50 by jinpark           #+#    #+#             */
/*   Updated: 2019/08/16 15:10:35 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	c_minus_print_func(char c, t_store *a)
{
	int i;

	i = -1;
	ft_putchar(c);
	while (++i < (a->wid - 1))
		ft_putchar(' ');
}

static void	c_print_func(char c, t_store *a)
{
	int i;

	i = -1;
	while (++i < (a->wid - 1))
		ft_putchar(' ');
	ft_putchar(c);
}

int			c_specifier(char *str, va_list *ap, t_store *a, int i)
{
	char	c;
	int		res;

	res = 0;
	c = (char)va_arg(*ap, int);
	if (str[i + 1] == '-')
		c_minus_print_func(c, a);
	else
		c_print_func(c, a);
	res = res_handler(a);
	return (res);
}
