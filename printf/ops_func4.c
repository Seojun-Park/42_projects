/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_func4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:57:01 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/26 22:59:55 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char g_d[] = "0123456789abcdef";
static char g_bd[] = "0123456789ABCDEF";

char	*itoa_base(uint32_t di, int base)
{
	int		len;
	char	*new;

	len = get_len_base(di, base);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (di == 0)
	{
		new[0] = '0';
		new[1] = '\0';
		return (new);
	}
	if (new == 0)
		return (NULL);
	new[len] = '\0';
	while (di)
	{
		new[--len] = g_d[di % base];
		di /= base;
	}
	return (new);
}

char	*big_itoa_base(unsigned int di, int base)
{
	int		len;
	char	*new;

	len = get_len_base(di, base);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (di == 0)
	{
		new[0] = '0';
		new[1] = '\0';
		return (new);
	}
	if (new == 0)
		return (NULL);
	new[len] = '\0';
	while (di)
	{
		new[--len] = g_bd[di % base];
		di /= base;
	}
	return (new);
}

char	*p_itoa_base(uint64_t di, int base)
{
	int		len;
	char	*new;

	len = get_len_base(di, base);
	new = (char *)malloc(sizeof(char) * len);
	if (new == 0)
		return (NULL);
	new[len - 1] = '\0';
	while (di)
	{
		new[--len] = g_d[di % base];
		di /= base;
	}
	return (new);
}

int		f_op_get_prec(char *str, int i)
{
	int		n;
	int		prec;
	char	*temp;

	prec = 0;
	n = i + 1;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str)));
	if (str[n] == '-')
		n++;
	while (str[n] != '.' && (str[n] >= '0' && str[n] <= '9'))
		n++;
	n++;
	while (str[n] >= '0' && str[n] <= '9')
		temp[prec++] = str[n++];
	temp[prec] = '\0';
	prec = ft_atoi(temp);
	free(temp);
	return (prec);
}

char	*ld_long_itoa(int64_t di)
{
	int		len;
	char	*new;

	len = get_len(di);
	new = (char *)malloc(sizeof(char) * (len + 1));
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
