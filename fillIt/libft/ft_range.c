/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:03:07 by jinpark           #+#    #+#             */
/*   Updated: 2020/01/07 18:21:36 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int	*tab;
	int i;

	if (min >= max)
		return (NULL);
	tab = (int *)malloc(sizeof(int *) * (max - min));
	i = 0;
	while (min <= max)
	{
		tab [i] = min;
		i++;
		min++;
	}
	return (tab);
}
