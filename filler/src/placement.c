/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <jinpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:04:02 by xinpark           #+#    #+#             */
/*   Updated: 2019/08/09 22:20:11 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				valid_pos_checker(t_filler *f, int y, int x)
{
	if (f->heat_map[y][x + 1] && f->heat_map[y][x + 1] == f->check)
		return (1);
	else if (x != 0 && f->heat_map[y][x - 1] == f->check)
		return (1);
	else if (f->heat_map[y + 1] && f->heat_map[y + 1][x] == f->check)
		return (1);
	else if (y != 0 && f->heat_map[y - 1][x] == f->check)
		return (1);
	return (0);
}

int				implement_nbr(t_filler *f)
{
	int			y;
	int			x;

	y = 0;
	f->flag = 0;
	while (y < f->map.height)
	{
		x = 0;
		while (x < f->map.width)
		{
			if (f->heat_map[y][x] == -1)
			{
				if (valid_pos_checker(f, y, x) == 1)
				{
					f->flag = 1;
					f->heat_map[y][x] = f->check + 1;
				}
			}
			x++;
		}
		y++;
	}
	return (f->flag);
}

static int		**fill_the_map(t_filler *f)
{
	int			y;
	int			x;

	y = 0;
	while (y < f->map.height)
	{
		x = 0;
		while (x < f->map.width)
		{
			if (f->map.map[y][x] == '.')
				f->heat_map[y][x] = -1;
			else if (f->map.map[y][x] == 'O' || f->map.map[y][x] == 'o')
				f->heat_map[y][x] = -2;
			else if (f->map.map[y][x] == 'X' || f->map.map[y][x] == 'x')
				f->heat_map[y][x] = 1;
			x++;
		}
		f->heat_map[y][x] = 0;
		y++;
	}
	f->heat_map[y] = NULL;
	return (f->heat_map);
}

void			build_heat_map(t_filler *f)
{
	int			y;

	f->heat_map = (int **)malloc(sizeof(int *) * (f->map.height + 1));
	y = -1;
	while (++y < f->map.height)
	{
		f->heat_map[y] = (int *)malloc(sizeof(int) * (f->map.width + 1));
		f->heat_map[y][f->map.width] = 0;
	}
	f->heat_map[f->map.height] = NULL;
	f->heat_map = fill_the_map(f);
}

void			placement(t_filler *f)
{
	int			y;
	int			x;

	f->check = 1;
	build_heat_map(f);
	while (implement_nbr(f) == 1)
		f->check++;
	f->max_cnt = 101010;
	y = 0;
	while (y < f->map.height)
	{
		x = 0;
		while (x < f->map.width)
		{
			find_place(f, y, x);
			x++;
		}
		y++;
	}
	ft_printf("%d %d\n", f->final_pos.y, f->final_pos.x);
}
