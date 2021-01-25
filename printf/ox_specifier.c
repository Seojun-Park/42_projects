/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:45:28 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/26 16:27:34 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	o_specifier(char *str, va_list *ap, t_store *a, int i)
{
	unsigned int	di;
	int				j;
	char			*temp;

	di = di_get_value(ap, a);
	temp = itoa_base(di, OCTET);
	a->len = ft_strlen(temp);
	j = res_handler(a);
	a->wid = width_handler(a);
	if (str[i + 1] == '-')
		d_minus_print_func(temp, a);
	else if (str[i + 1] == '0')
		d_print_func_zero(temp, a);
	else if (str[i + 1] == '#' && di != 0)
		o_print_func_hash(temp, a);
	else
		d_print_func(temp, a);
	if (str[i + 1] == '#' && di != 0)
		j += 1;
	free(temp);
	return (j);
}

int	x_specifier(char *str, va_list *ap, t_store *a, int i)
{
	int64_t	di;
	int		j;
	char	*temp;

	di = di_get_value(ap, a);
	if (di > U_MAX)
		temp = p_itoa_base(di, HEXA);
	else
		temp = itoa_base(di, HEXA);
	a->len = ft_strlen(temp);
	j = res_handler(a);
	a->wid = width_handler(a);
	if (str[i + 1] == '-')
		d_minus_print_func(temp, a);
	else if (str[i + 1] == '0')
		d_print_func_zero(temp, a);
	else if (str[i + 1] == '#')
		d_print_func_hash(temp, a);
	else
		d_print_func(temp, a);
	if (str[i + 1] == '#')
		j += 2;
	free(temp);
	return (j);
}

int	bx_specifier(char *str, va_list *ap, t_store *a, int i)
{
	int64_t	di;
	int		j;
	char	*temp;

	di = di_get_value(ap, a);
	if (di > U_MAX)
		temp = p_itoa_base(di, HEXA);
	else
		temp = big_itoa_base(di, HEXA);
	a->len = ft_strlen(temp);
	j = res_handler(a);
	a->wid = width_handler(a);
	if (str[i + 1] == '-')
		d_minus_print_func(temp, a);
	else if (str[i + 1] == '0')
		d_print_func_zero(temp, a);
	else if (str[i + 1] == '#')
		d_print_func_bhash(temp, a);
	else
		d_print_func(temp, a);
	if (str[i + 1] == '#')
		j += 2;
	free(temp);
	return (j);
}
