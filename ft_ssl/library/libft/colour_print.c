/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 22:10:26 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/23 14:48:04 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_colour g_t[] =
{
	{"{red}", "\033[0;31m"},
	{"{green}", "\033[0;32m"},
	{"{yellow}", "\033[0;33m"},
	{"{blue}", "\033[0;34m"},
	{"{purple}", "\033[0;35m"},
	{"{cyan}", "\033[0;36m"},
	{"{reset}", "\033[0;[0m"},
	{NULL, NULL},
};

void	colour_print(char **s, int *res)
{
	int		i;
	char	colour[2147483647];

	i = 0;
	while (**s != '}' && **s != '\0')
	{
		colour[i++] = **s;
		*s += 1;
		if (**s == '}')
			colour[i++] = '}';
	}
	colour[i] = '\0';
	i = -1;
	while (ft_strlen(colour) < 11 && g_t[++i].colour)
	{
		if (ft_strcmp(colour, g_t[i].colour) == 0)
		{
			ft_putstr(g_t[i].code);
			*s += 1;
			return ;
		}
	}
	ft_printf("\033[0m%s", colour);
	*res += ft_strlen(colour);
	**s != '\0' ? *s += 1 : 0;
}
