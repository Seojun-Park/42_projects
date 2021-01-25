/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:43:19 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/26 14:31:29 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const	t_dt g_dt[] =
{
	{'c', c_specifier},
	{'s', s_specifier},
	{'d', di_specifier},
	{'i', di_specifier},
	{'f', f_specifier},
	{'x', x_specifier},
	{'X', bx_specifier},
	{'o', o_specifier},
	{'u', u_specifier},
	{'p', p_specifier},
	{'%', percent_sp},
	{0, NULL},
};

void	check_ops(t_store *a, char *str, int i)
{
	a->wid = op_get_wid(str, i);
	a->prec = op_get_prec(str, i);
	a->plus = op_get_plus(str, i);
	a->space = op_get_space(str, i);
	a->zero = op_get_zero(str, i);
	if (a->plus == 1)
		a->wid -= 1;
	if (a->space == 1)
		a->wid -= 1;
}

int		spe_handler(char *str, t_store *a, va_list *ap, int i)
{
	size_t	n;
	int		res;
	char	conv;

	n = -1;
	conv = find_conv(str, i);
	a->l_cnt = l_check(str, i, conv);
	a->h_cnt = h_check(str, i, conv);
	a->bl_cnt = bl_check(str, i, conv);
	while (++n < ft_strlen(SPECIFIER))
	{
		if (g_dt[n].specifier == conv)
			res = g_dt[n].function(str, ap, a, i);
	}
	return (res);
}

int		formatting(char *str, va_list *ap, int i)
{
	t_store	a;
	int		res;

	ft_bzero(&a, sizeof(t_store));
	check_ops(&a, str, i);
	res = spe_handler(str, &a, ap, i);
	return (res);
}
