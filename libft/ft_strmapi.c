/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:28:04 by jinpark           #+#    #+#             */
/*   Updated: 2019/02/19 22:01:39 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	i = 0;
	j = 0;
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = (*f)(j, s[i]);
		i++;
		j++;
	}
	return (new);
}
