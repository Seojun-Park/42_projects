/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_func7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:11:03 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/27 14:08:41 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_minuszero(char *new, char c)
{
	new[0] = c;
	new[1] = '0';
	new[2] = '.';
	new[3] = '\0';
	return (new);
}

int		bl_check(char *str, int n, char c)
{
	int i;
	int cnt;

	i = n;
	cnt = 0;
	while (str[i++] != c)
	{
		if (str[i] == 'L')
			cnt++;
	}
	return (cnt);
}

void	d_print_func_bhash(char *s, t_store *a)
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
	ft_putstr("0X");
	if (prec != 0)
		while (++i < prec)
			ft_putchar('0');
	i = -1;
	if (len != 0)
		while (++i < a->len)
			ft_putchar(s[i]);
}
