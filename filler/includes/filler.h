/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <jinpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 19:40:30 by jinpark           #+#    #+#             */
/*   Updated: 2019/08/10 16:44:07 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_data
{
	int			height;
	int			width;
	// int			size;
	char		**map;
}				t_data;

typedef struct	s_filler
{
	char		p_id;
	t_data		map;
	t_data		token;
	char		e_id;
	int			check;
	int			max_cnt;
	int			flag;
	int			**heat_map;
	t_pos		final_pos;
}				t_filler;

void			find_place(t_filler *f, int i, int j);
void			placement(t_filler *f);
void			free_maps(t_filler *f);

#endif
