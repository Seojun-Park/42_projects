/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:59:35 by jinpark           #+#    #+#             */
/*   Updated: 2019/03/19 20:49:35 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tet	*create_tetrimino(void)
{
	t_tet *piece;

	piece = (t_tet*)malloc(sizeof(t_tet));
	if (piece == NULL)
		return (NULL);
	return (piece);
}

static int		find_origin(char *tetrimino, int index)
{
	while (tetrimino[index] != '#')
		++index;
	return (index);
}

static t_tet	*read_tetrimino(char *tetrimino, int index)
{
	t_tet	*piece;
	int		newline;
	int		origin;
	int		i;

	i = 0;
	index = find_origin(tetrimino, index);
	origin = index;
	newline = 0;
	piece = create_tetrimino();
	while (i < 4)
	{
		if (tetrimino[index] == '\n')
		{
			++newline;
			origin += 5;
		}
		if (tetrimino[index] == '#')
		{
			piece->x[i] = (index - origin);
			piece->y[i++] = newline;
		}
		index++;
	}
	return (piece);
}

t_tet			**read_all_tetrimino(char *tetrimino)
{
	t_tet	**puzzle;
	int		count;
	int		i;
	int		j;
	char	c;

	count = (ft_strlen(tetrimino) + 1) / 21;
	puzzle = (t_tet**)malloc(sizeof(t_tet*) * (count + 1));
	i = 0;
	j = 0;
	c = 'A';
	while (j < count)
	{
		puzzle[j] = read_tetrimino(tetrimino, i);
		puzzle[j]->c = c;
		c++;
		i += 21;
		j++;
	}
	puzzle[j] = NULL;
	return (puzzle);
}
