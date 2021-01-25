/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_func3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:39:33 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/26 14:25:54 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double	ft_power(int n, int p)
{
	double	result;

	result = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}

int		l_check(char *str, int n, char c)
{
	int i;
	int cnt;

	i = n;
	cnt = 0;
	while (str[i++] != c)
	{
		if (str[i] == 'l')
			cnt++;
	}
	return (cnt);
}

int		h_check(char *str, int n, char c)
{
	int	i;
	int cnt;

	i = n;
	cnt = 0;
	while (str[i++] != c)
	{
		if (str[i] == 'h')
			cnt++;
	}
	return (cnt);
}

int		op_get_plus(char *str, int i)
{
	int n;

	n = i + 1;
	if ((str[n] != 'a' && str[n] != 'z') && str[n] != '%' && str[n] != 0)
	{
		while ((str[n] != 'a' && str[n] != 'z') && str[n] != '%' && str[n] != 0)
		{
			if (str[n] == '+')
				return (1);
			n++;
		}
	}
	return (0);
}

int64_t	change_num(int64_t num, int i)
{
	int64_t res;

	res = 0;
	if (num < i)
		return (num);
	else
	{
		res += change_num(num / i, i) * 10;
		res += num % i;
	}
	return (res);
}
