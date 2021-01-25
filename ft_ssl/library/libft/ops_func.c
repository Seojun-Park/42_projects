/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:11:05 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/22 19:35:45 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		op_get_wid(char *str, int i)
{
	int		wid;
	int		n;
	char	*temp;

	n = i + 1;
	wid = 0;
	temp = malloc(sizeof(char) * (ft_strlen(str)));
	if (str[n] == ' ' || str[n] == '-' || str[n] == '+' || str[n] == '0')
	{
		while (str[n] == ' ' || str[n] == '-' || str[n] == '+' || str[n] == '0')
			n++;
	}
	while (str[n] >= '0' && str[n] <= '9')
		temp[wid++] = str[n++];
	temp[wid] = '\0';
	wid = ft_atoi(temp);
	free(temp);
	return (wid);
}

int		op_get_prec(char *str, int i)
{
	int		prec;
	int		n;
	char	*temp;

	n = i + 1;
	prec = 0;
	temp = malloc(sizeof(char) * (ft_strlen(str)));
	if (str[n] == ' ' || str[n] == '-' || str[n] == '+')
		n++;
	while (str[n] != '.' && (str[n] >= '0' && str[n] <= '9'))
		n++;
	if (str[n] == '.')
	{
		n++;
		while (str[n] >= '0' && str[n] <= '9')
			temp[prec++] = str[n++];
	}
	temp[prec] = '\0';
	prec = ft_atoi(temp);
	free(temp);
	return (prec);
}

char	find_conv(char *str, int n)
{
	int		i;
	int		j;

	i = n + 1;
	while (str[i] != '\0')
	{
		j = 0;
		while (SPECIFIER[j] != '\0')
		{
			if (str[i] == SPECIFIER[j])
				return (SPECIFIER[j]);
			j++;
		}
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int64_t	di_get_value(va_list *ap, t_store *a)
{
	if (a->l_cnt == 1)
		return ((long)va_arg(*ap, long));
	else if (a->l_cnt == 2)
		return ((unsigned long long)va_arg(*ap, long long));
	else if (a->h_cnt == 1)
		return ((short)va_arg(*ap, int));
	else if (a->h_cnt == 2)
		return ((signed char)va_arg(*ap, int));
	else
		return ((int)va_arg(*ap, int));
}

int		width_handler(t_store *a)
{
	if (a->wid > a->prec && a->wid > a->len)
	{
		if (a->prec > a->len)
		{
			a->wid -= a->prec;
			return (a->wid);
		}
		else if (a->len >= a->prec)
		{
			a->wid -= a->len;
			return (a->wid);
		}
	}
	else if (a->wid <= a->prec || a->wid <= a->len)
		return (0);
	return (a->wid);
}
