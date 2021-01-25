/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:10:35 by jinpark           #+#    #+#             */
/*   Updated: 2019/02/19 21:32:46 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ss;
	size_t	i;

	ss = (char *)s;
	i = 0;
	while (i++ < n)
	{
		if (*ss == (char)c)
			return ((char *)ss);
		ss++;
	}
	return (NULL);
}
