/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:53:43 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/23 19:29:31 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		p_specifier(char *str, va_list *ap, t_store *a, int i)
{
	void		*p;
	uint64_t	ptr;
	int			j;
	char		*temp;

	(void)i;
	j = 0;
	if (*str != '\0')
	{
		p = va_arg(*ap, void *);
		ptr = *((uint64_t *)(&p));
		temp = p_itoa_base(ptr, HEXA);
		a->len = ft_strlen(temp);
		j = res_handler(a);
		a->wid = width_handler(a);
		ft_putstr("0x");
		if (p == 0)
			ft_putchar('0');
		else
			ft_putstr(temp);
		j += 2;
		free(temp);
	}
	return (j);
}

int		percent_sp(char *str, va_list *ap, t_store *a, int i)
{
	(void)ap;
	if (str[i + 1] == '-')
		percent_minus_print(a);
	else
		percent_print(a);
	return (res_handler(a));
}

void	percent_print(t_store *a)
{
	int i;
	
	i = 0;
	if (a->wid != 0)
		while (++i < a->wid)
			ft_putchar(' ');
	ft_putchar('%');
}

void percent_minus_print(t_store *a)
{
	int i;

	i = 0;
	ft_putchar('%');
	if (a->wid != 0)
		while (++i < a->wid)
			ft_putchar(' ');
}
