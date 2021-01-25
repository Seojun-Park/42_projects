/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <jinpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 22:10:26 by jinpark           #+#    #+#             */
/*   Updated: 2019/08/16 14:45:01 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		colour_print(char *s, int index)
{
	int		i;
	int		j;
	char	colour[10];

	i = index;
	j = 0;
	while (s[i] != '}' && s[i] != '\0')
	{
		colour[j] = s[i];
		if (s[i + 1] == '}')
			colour[j + 1] = '}';
		i++;
		j++;
	}
	colour[j + 1] = '\0';
	i = -1;
	while (g_t[++i].colour)
	{
		if (ft_strcmp(colour, g_t[i].colour) == 0)
		{
			ft_putstr(g_t[i].code);
			return (ft_strlen(colour) - 1);
		}
	}
	ft_printf("\033[0m%s", colour);
	if (s[i] != '\0')
		return (ft_strlen(colour) - 1);
	else
		return (0);
}