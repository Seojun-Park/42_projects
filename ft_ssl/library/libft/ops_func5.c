/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_func5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:39:04 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/26 16:24:54 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*f_long_itoa(int64_t di)
{
	int		len;
	char	*new;

	len = fp_get_len(di);
	new = (char *)malloc(sizeof(char) * (len + 2));
	if (di == 0)
	{
		new[0] = '0';
		new[1] = '\0';
		return (new);
	}
	if (di < 0)
	{
		new[0] = '-';
		di *= -1;
	}
	new[len] = '\0';
	while (di)
	{
		new[--len] = (di % 10) + '0';
		di /= 10;
	}
	return (new);
}

char	*f_ipart(int64_t ipart, t_store *a)
{
	char *new;
	int i;

	if (ipart < INT_MIN)
		new = f_long_itoa(ipart);
	else
		new = long_itoa(ipart);
	i = ft_strlen(new);
	new[i] = '.';
	new[i + 1] = '\0';
	if (ipart == 0 && a->f_minus == 1)
		set_minuszero(new, '-');
	return (new);
}

char	*ft_ftoa_f(unsigned long n)
{
	int		len;
	int		i;
	char	*new;

	len = f_get_len(n);
	if (len < 6)
		len = len + (6 - len);
	new = malloc(sizeof(char) * len + 1);
	i = len;
	ft_memset(new, '0', i);
	while (len-- != 0)
	{
		new[len] = (n % 10) + '0';
		n /= 10;
	}
	new[i] = '\0';
	return (new);
}

int		get_len_base(uint64_t num, int base)
{
	int			i;
	uint64_t	n;

	i = 0;
	n = num;
	if (num == 0)
		i++;
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

void	d_print_func_hash(char *s, t_store *a)
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
	ft_putstr("0x");
	if (prec != 0)
		while (++i < prec)
			ft_putchar('0');
	i = -1;
	if (len != 0)
		while (++i < a->len)
			ft_putchar(s[i]);
}
