/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:38:29 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/22 19:05:20 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	new[len] = '\0';
	return (new);
}
