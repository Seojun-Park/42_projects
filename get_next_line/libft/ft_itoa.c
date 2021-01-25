/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:53:32 by jinpark           #+#    #+#             */
/*   Updated: 2019/02/19 23:40:59 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		get_len(int n)
{
	int	i;

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

char			*ft_itoa(int n)
{
	int		len;
	char	*new;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = get_len(n);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (new == 0)
		return (NULL);
	new[len] = 0;
	if (n < 0)
	{
		new[0] = '-';
		n *= -1;
	}
	while (n)
	{
		new[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (new);
}
