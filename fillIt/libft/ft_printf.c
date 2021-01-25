/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:41:16 by jinpark           #+#    #+#             */
/*   Updated: 2019/06/17 13:38:51 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_lenth(char *str, int i)
{
	int n;
	int cnt;

	cnt = 1;
	n = i;
	if (str[i] == '%')
		i++;
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' ||
			str[i] == '-' || str[i] == '+' || str[i] == 'l' ||
			str[i] == 'h' || str[i] == 'L' || str[i] == '#' ||
			str[i] == ' ')
	{
		while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' ||
			str[i] == '-' || str[i] == '+' || str[i] == 'l' ||
			str[i] == 'h' || str[i] == 'L' || str[i] == '#' ||
			str[i] == ' ')
		{
			cnt++;
			i++;
		}
	}
	return (cnt);
}

int			ft_printf(char *str, ...)
{
	va_list	ap;
	int		cnt;
	int		res;
	int		i;

	i = -1;
	res = 0;
	va_start(ap, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			res += formatting(str, &ap, i);
			cnt = count_lenth(str, i);
			i += cnt;
		}
		else
		{
			ft_putchar(str[i]);
			res++;
		}
	}
	va_end(ap);
	return (res);
}
