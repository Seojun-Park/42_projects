/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:27:13 by jinpark           #+#    #+#             */
/*   Updated: 2020/01/07 18:20:47 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int		i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
