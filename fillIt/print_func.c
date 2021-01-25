/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:15:47 by jinpark           #+#    #+#             */
/*   Updated: 2019/03/19 20:48:32 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		++i;
	}
}

void	print_tetrimino(t_tet *tetrimino)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putnbr(tetrimino->x[i]);
		ft_putchar(' ');
		ft_putnbr(tetrimino->y[i]);
		ft_putchar('\n');
		++i;
	}
	ft_putchar('\n');
}
