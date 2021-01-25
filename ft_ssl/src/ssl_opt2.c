/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.opt2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:04:35 by jinpark           #+#    #+#             */
/*   Updated: 2019/06/19 21:41:52 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	print_by_flags(int i, char **argv, t_ssl *ssl)
{
	if (ssl->flags.r != 0)
		ft_printf(" \"%s\"\n", argv[i + 1]);
	if (ssl->flags.s != 0 && ssl->flags.r == 0)
		ft_putchar('\n');
}

void	go_here(int i, char **argv, t_ssl *ssl)
{
	int n;

	n = i + 1;
	while (argv[n] != '\0')
	{
		if (argv[n][1] == 's')
			ft_printf("ft_ssl: %s: -s: No such file or directory\n",
					ssl->dp.command);
		else
			ft_printf("ft_ssl: %s: %s: No such file or directory\n",
					ssl->dp.command, argv[n]);
		n++;
	}
}

void	error_message(char *argv)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", argv);
	ft_printf("Standard	commands:\n\n");
	ft_printf("Message Digest commands:\nmd5\nsha256\n\n");
	ft_printf("Cipher commands:\n");
}

void	error_usage(void)
{
	ft_printf("usage: command [command options] [command args]\n");
}

unsigned int	right_rotate_64(unsigned int x, unsigned int c)
{
	return ((x >> c) | (x << (64 - c)));
}
