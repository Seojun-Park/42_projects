/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:43:02 by jinpark           #+#    #+#             */
/*   Updated: 2020/01/07 18:18:56 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_if(char **tab, int(*f)(char *))
{
	int		i;
	int		nb;
	int		len;

	i = 0;
	nb = 0;
	len = 0;
	if (tab[0] != NULL)
		len = ft_strlen(tab[0]);
	while (tab[i][0] != '0')
	{
		if (f(tab[i]) == 1)
			nb++;
		i++;
		if (i == len)
			break ;
	}
	return (nb);
}
