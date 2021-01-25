/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 20:21:46 by jinpark           #+#    #+#             */
/*   Updated: 2019/04/05 15:13:33 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_tet {
	int			x[4];
	int			y[4];
	char		c;
}				t_tet;

typedef struct	s_map {
	char		**array;
	int			xmax;
	int			ymax;
}				t_map;

typedef struct	s_char {
	int			hash;
	int			dot;
	int			newline;
}				t_char;

char			*extract_tetrimino(char *filename);
t_tet			**read_all_tetrimino(char *tetrimino);
void			free_map(t_map *map);
char			**new_array(int x, int y);
int				load_tetrimino(t_tet *t, t_map *map, int x, int y);
void			remove_tetrimino(t_tet *t, t_map *map, int x, int y);
t_map			*starting_map(char *tetrimino);
t_map			*resize_map(t_map *old_map);
void			print_array(char **array);
void			print_tetrimino(t_tet *tetrimino);
char			**fillit(char *tetrimino);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int num);
size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strnew(size_t size);
int				check_colrow(char *str, int tet);
void			*ft_memset(void *b, int c, size_t len);
int				main_check(char *str);
int				check_hash(char *str);

#endif
