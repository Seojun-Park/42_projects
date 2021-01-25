/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <jinpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:17:05 by jinpark           #+#    #+#             */
/*   Updated: 2019/08/06 18:06:57 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			final_position(t_filler *f, int i, int j)
{
	int		x;
	int		y;
	int		tmp;

	tmp = 0;
	y = 0;
	while (y < f->token.height)
	{
		x = 0;
		while (x < f->token.width)
		{
			if (f->token.map[y][x] == '*' && f->heat_map[i + y][j + x] > 1)
				tmp = f->heat_map[i + y][j + x];
			x++;
		}
		y++;
	}
	return (tmp);
}

int			check_and_count(t_filler *f, int i, int j)
{
	int		y;
	int		x;
	int		cnt;

	y = -1;
	cnt = 0;
	while (++y < f->token.height)
	{
		if (i + y >= f->map.height)
			return (-1);
		x = -1;
		while (++x < f->token.width)
		{
			if (f->token.map[y][x] == '*' && (f->map.map[y + i][x + j] == 'O'
			|| f->map.map[y + i][x + j] == f->p_id + 32))
				cnt++;
			if ((j + x >= f->map.width) || (f->token.map[y][x] == '*'
			&& (f->map.map[y + i][x + j] == f->e_id ||
			f->map.map[y + i][x + j] == f->e_id + 32)))
				return (-1);
		}
	}
	if (cnt != 1)
		return (-1);
	return (1);
}

void		free_maps(t_filler *f)
{
	int i;

	i = -1;
	if (f->map.map != NULL)
	{
		while (++i < f->map.height)
			free(f->map.map[i]);
		free(f->map.map);
	}
	i = -1;
	if (f->token.map != NULL)
	{
		while (++i < f->token.height)
			free(f->token.map[i]);
		free(f->token.map);
	}
	i = -1;
	if (f->heat_map != NULL)
	{
		while (++i < f->map.height)
			free(f->heat_map[i]);
		free(f->heat_map);
	}
}

void		find_place(t_filler *f, int i, int j)
{
	int		tmp;

	tmp = 0;
	if (check_and_count(f, i, j) == 1)
	{
		tmp = final_position(f, i, j);
		if (f->max_cnt > tmp)
		{
			f->max_cnt = tmp;
			f->final_pos.y = i;
			f->final_pos.x = j;
		}
	}
}
