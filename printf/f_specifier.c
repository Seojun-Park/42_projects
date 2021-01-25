/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:59:53 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/26 23:14:08 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static double	fpart_round_up(double f, int prec)
{
	int		len;
	double	res;
	double	magic;
	double	temp;

	temp = f * ft_power(10, prec + 1);
	len = f_get_len(temp);
	magic = 0.45;
	if (len > prec)
	{
		magic = magic / ft_power(10, prec);
		res = f + magic;
		return (res);
	}
	temp = f;
	return (f);
}

static char		*f_expander(double fpart, int prec)
{
	char	*temp;
	double	f;
	int		p;

	temp = malloc(sizeof(char) * prec);
	if (prec != 0)
	{
		p = prec;
		f = fpart_round_up(fpart, p);
		f = f * ft_power(10, p);
		temp = ft_ftoa_f((unsigned long)f);
	}
	else if (prec == 0)
	{
		f = round_up_check(fpart);
		f = f * ft_power(10, 6);
		temp = ft_ftoa_f((unsigned long)f);
	}
	return (temp);
}

static char		*f_fpart(double fpart, int prec)
{
	char	*temp;

	if (fpart < 0)
		fpart *= -1;
	if (fpart == 0)
	{
		temp = ft_strnew(7);
		temp = ft_memset(temp, '0', 6);
		return (temp);
	}
	else
	{
		temp = f_expander(fpart, prec);
		return (temp);
	}
}

char			*ftoa(double n, t_store *a)
{
	int64_t	ipart;
	double	fpart;
	char	*new;
	char	*temp;

	if (n < 0)
		a->f_minus = 1;
	ipart = (int64_t)n;
	fpart = n - (double)ipart;
	new = f_ipart(ipart, a);
	temp = f_fpart(fpart, a->prec);
	new = ft_strjoin(new, temp);
	free(temp);
	return (new);
}

int				f_specifier(char *str, va_list *ap, t_store *a, int n)
{
	int		i;
	char	*temp;
	double	f;

	f = 0;
	f = f_get_value(ap, a);
	a->prec = f_op_get_prec(str, n);
	if (str[n + 1] == '-')
	{
		temp = ftoa(f, a);
		f_minus_print_func(temp, a);
	}
	else
	{
		temp = ftoa(f, a);
		f_print_func(temp, a);
	}
	i = ft_strlen(temp);
	free(temp);
	return (i);
}
