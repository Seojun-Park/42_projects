/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:59:29 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/23 20:18:28 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char error[] = "(null)";

static void	s_print_func(char *s, t_store *a)
{
	int i;
	int space;

	i = 0;
	if (s[0] == '-')
		a->prec = a->prec + 1;
	if (a->prec > a->len)
		a->prec = a->len;
	space = a->wid - a->prec;
	if (space > 0)
	{
		while (i++ < space)
			ft_putchar(' ');
	}
	i = -1;
	if (a->prec > 0)
	{
		while (++i < a->prec)
			ft_putchar(s[i]);
	}
	else
		while (s[++i] != '\0')
			ft_putchar(s[i]);
}

static void	s_minus_print_func(char *s, t_store *a)
{
	int i;
	int space;

	if (a->prec > a->len + 1)
		a->prec = a->len;
	space = a->wid - a->prec;
	i = -1;
	if (a->prec >= 0)
	{
		while (++i < a->prec)
			ft_putchar(s[i]);
	}
	i = 0;
	while (space > i++)
		ft_putchar(' ');
}

int			s_specifier(char *str, va_list *ap, t_store *a, int i)
{
	char *s;

	s = va_arg(*ap, char *);
	if (s == NULL)
	{
		ft_putstr(error);
		return (ft_strlen(error));
	}
	a->len = ft_strlen(s);
	if (str[i + 1] == '-')
		s_minus_print_func(s, a);
	else
		s_print_func(s, a);
	if (a->wid > a->prec && a->wid > a->len)
		return (a->wid);
	else if (a->prec > a->wid && a->prec > a->len)
		return (a->prec);
	else if (a->len > a->wid && a->len > a->prec)
		return (a->len);
	return (0);
}
