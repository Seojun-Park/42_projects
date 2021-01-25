/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <jinpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 21:16:50 by jinpark           #+#    #+#             */
/*   Updated: 2019/08/10 16:45:02 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			read_map(char *line, t_data *map, int fd)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_strsplit(line, ' ');
	map->height = ft_atoi(split[1]);
	map->width = ft_atoi(split[2]);
	while (++i < 3)
		free(split[i]);
	free(split);
	// map->size = map->height * map->width;
	map->map = (char **)malloc((map->height + 1) * sizeof(char *));
	get_next_line_link(fd, &line);
	free(line);
	i = -1;
	while (++i < map->height)
		map->map[i] = (char *)malloc((map->width + 1) * sizeof(char));
	i = -1;
	while (++i < map->height)
	{
		get_next_line_link(fd, &line);
		map->map[i] = ft_strcpy(map->map[i], (line + 4));
		ft_strdel(&line);
	}
	map->map[i] = NULL;
	free(line);
}

void			read_token(char *line, t_data *token, int fd)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_strsplit(line, ' ');
	token->height = ft_atoi(split[1]);
	token->width = ft_atoi(split[2]);
	while (++i < 3)
		free(split[i]);
	free(split);
	// token->size = token->height * token->width;
	token->map = (char **)malloc((token->height + 1) * sizeof(char *));
	i = -1;
	while (++i < token->height)
		token->map[i] = (char *)malloc((token->width + 1) * sizeof(char));
	i = 0;
	while (i < token->height)
	{
		get_next_line_link(fd, &line);
		token->map[i] = ft_strcpy(token->map[i], line);
		ft_strdel(&line);
		i++;
	}
	free(line);
	token->map[token->height] = NULL;
}

void			player_set(t_filler *f, char *line)
{
	if (line[10] == '1')
	{
		f->p_id = 'O';
		f->e_id = 'X';
	}
	else
	{
		f->p_id = 'X';
		f->e_id = 'O';
	}
}

void			main_loop(t_filler *f, char *line, int fd)
{
	int			i;

	i = 0;
	while (get_next_line_link(fd, &line) > 0)
	{
		if (line == NULL)
			continue ;
		if (ft_strncmp(line, "Plateau ", 8) == 0)
			read_map(line, &f->map, fd);
		else if (ft_strncmp(line, "Piece ", 6) == 0)
		{
			read_token(line, &f->token, fd);
			placement(f);
		}
		free(line);
	}
	free_maps(f);
}

int				main(void)
{
	t_filler	f;
	char		*line;
	int			fd;

	ft_bzero(&f, sizeof(t_filler));
	line = NULL;
	fd = 0;
	// fd = open("file", O_RDONLY);
	if (get_next_line_link(fd, &line) > 0)
	{
		if (line[10] == '1')
			player_set(&f, line);
		main_loop(&f, line, fd);
		free(line);
	}
	return (0);
}
