/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:05:26 by jinpark           #+#    #+#             */
/*   Updated: 2019/03/19 20:47:57 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**new_array(int x, int y)
{
	char	**array;
	int		i;
	int		j;

	j = 0;
	array = (char**)malloc(sizeof(char*) * (y + 1));
	while (j < y)
	{
		i = 0;
		array[j] = (char*)malloc(sizeof(char) * (x + 1));
		while (i < x)
		{
			array[j][i] = '.';
			i++;
		}
		array[j][i] = '\0';
		j++;
	}
	array[j] = NULL;
	return (array);
}

static int		starting_size(char *tetrimino)
{
	int x;
	int area;
	int square;

	x = 0;
	square = 0;
	area = ((ft_strlen(tetrimino) + 1) / 21) * 4;
	while ((x++ * square++) < area)
		;
	return (x - 1);
}

t_map			*starting_map(char *tetrimino)
{
	int		x;
	int		y;
	t_map	*map;

	x = starting_size(tetrimino);
	y = x;
	map = (t_map*)malloc(sizeof(t_map));
	map->array = new_array(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}

t_map			*resize_map(t_map *old_map)
{
	int		x;
	int		y;
	t_map	*map;

	x = old_map->xmax + 1;
	y = old_map->ymax + 1;
	free_map(old_map);
	map = (t_map*)malloc(sizeof(t_map));
	map->array = new_array(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}
