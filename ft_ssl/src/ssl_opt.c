/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:37:46 by jinpark           #+#    #+#             */
/*   Updated: 2019/06/19 13:31:20 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

unsigned int	left_rotate(unsigned int x, unsigned int c)
{
	return ((x << c) | (x >> (32 - c)));
}

unsigned int	right_rotate(unsigned int x, unsigned int c)
{
	return ((x >> c) | (x << (32 - c)));
}

void			get_flags(int i, int argc, char **argv, t_ssl *ssl)
{
	while (*argv[i] != '\0')
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'p')
				ssl->flags.p = 1;
			else if (argv[i][1] == 'q')
				ssl->flags.q = 1;
			else if (argv[i][1] == 'r')
				ssl->flags.r = 1;
			if ((ssl->flags.r == 1) && (ssl->flags.q == 1))
			{
				ssl->flags.r = 0;
				ssl->flags.q = 2;
			}
			break ;
		}
		i++;
	}
}

void			byte_rev(unsigned int *c)
{
	unsigned int	num;
	int				i;

	num = 0;
	i = 0;
	num += *c & 0xff;
	num = LEFT_SHIFT;
	while (++i < 4)
	{
		num += *c >> (i * 8) & 0xff;
		if ((i * 8) == 24)
			break ;
		num = LEFT_SHIFT;
	}
	*c = num;
}

void			get_file(int fd, char *file_name, t_ssl *ssl)
{
	char			*temp;
	char			*data;

	if (get_next_line(fd, &temp) > 0)
	{
		data = ft_strjoin(temp, "\n");
		temp = ft_strdup(ssl->dp.command);
		if (!ssl->flags.q && !ssl->flags.r)
			ft_printf("%s (%s) = ", ft_utoupper(temp), file_name);
		ssl->dp.function(data);
		if (ssl->flags.r == 1)
			ft_printf("%c%s", ' ', file_name);
		ft_putchar('\n');
		free(data);
		free(temp);
	}
	else
		ft_printf("No such a file and directory\n");
	close(fd);
}
