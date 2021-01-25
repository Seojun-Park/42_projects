/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:29:36 by jinpark           #+#    #+#             */
/*   Updated: 2019/06/20 20:35:23 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			fp_get_len(int64_t n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int			f_get_len(double n)
{
	int i;

	i = 0;
	while (n > 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*long_itoa(int64_t di)
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
	new[len] = '\0';
	if (di < 0)
	{
		new[0] = '-';
		di *= -1;
	}
	while (di)
	{
		new[--len] = (di % 10) + '0';
		di /= 10;
	}
	return (new);
}

double		round_up_check(double f)
{
	f = f + 0.00000045;
	return (f);
}

long double	f_get_value(va_list *ap, t_store *a)
{
	if (a->bl_cnt != 0)
		return (va_arg(*ap, long double));
	if (a->l_cnt != 0)
		return (va_arg(*ap, double));
	else
		return (va_arg(*ap, double));
}
