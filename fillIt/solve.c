/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:19:10 by jinpark           #+#    #+#             */
/*   Updated: 2019/03/19 20:48:50 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		backtracking(t_tet **pieces, t_map *map, int i)
{
	int x;
	int y;

	if (pieces[i] == NULL)
		return (1);
	y = 0;
	while (y < map->ymax)
	{
		x = 0;
		while (x < map->xmax)
		{
			if (load_tetrimino(pieces[i], map, x, y))
			{
				if (backtracking(pieces, map, i + 1))
					return (1);
				else
					remove_tetrimino(pieces[i], map, x, y);
			}
			++x;
		}
		++y;
	}
	return (0);
}

char			**fillit(char *tetrimino)
{
	t_tet	**pieces;
	t_map	*map;

	pieces = read_all_tetrimino(tetrimino);
	map = starting_map(tetrimino);
	while (!backtracking(pieces, map, 0))
	{
		map = resize_map(map);
	}
	return (map->array);
}
