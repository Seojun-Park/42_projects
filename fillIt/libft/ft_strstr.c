/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:04:29 by jinpark           #+#    #+#             */
/*   Updated: 2019/02/19 22:06:37 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;

	if (*s2 == '\0')
		return ((char*)s1);
	else
	{
		while (*s1)
		{
			if (*s1 == *s2)
			{
				i = 0;
				while (*(s1 + i) == *(s2 + i))
				{
					i++;
					if (i == ft_strlen(s2))
						return ((char *)s1);
				}
			}
			s1++;
		}
	}
	return (NULL);
}
