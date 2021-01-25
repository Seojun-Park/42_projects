/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tetrimino.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:51:50 by jinpark           #+#    #+#             */
/*   Updated: 2019/03/19 20:46:37 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		legal_char(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (1);
		++i;
	}
	return (0);
}

static int		check_if_valid(char *str)
{
	int			len;

	len = ft_strlen(str);
	if (legal_char(str))
		return (1);
	if (main_check(str))
		return (1);
	if (check_hash(str))
		return (1);
	else
		return (0);
}

static char		*append_str(void *ptr, size_t size)
{
	void		*newptr;
	size_t		old_size;

	newptr = (char*)malloc(sizeof(char) * size);
	ft_memset(newptr, 0, size);
	old_size = ft_strlen(ptr);
	ft_memcpy(newptr, ptr, old_size);
	free(ptr);
	return (newptr);
}

char			*extract_tetrimino(char *filename)
{
	char		*tetrimino;
	char		*temp;
	int			fd;
	int			ret;
	int			size;

	size = 22;
	fd = open(filename, O_RDONLY);
	tetrimino = ft_strnew(21);
	temp = ft_strnew(21);
	while ((ret = read(fd, temp, 21)))
	{
		ft_strcat(tetrimino, temp);
		size += 21;
		tetrimino = append_str(tetrimino, size);
		ft_memset(temp, 0, 21);
	}
	if (check_if_valid(tetrimino))
	{
		ft_putstr("error\n");
		exit(1);
	}
	return (tetrimino);
}
