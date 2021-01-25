/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 21:27:28 by jinpark           #+#    #+#             */
/*   Updated: 2019/06/19 21:25:24 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int			find_command(char *argv)
{
	int		i;
	char	*temp;

	i = -1;
	while (g_ssl_dp[++i].command)
	{
		if (ft_strcmp(g_ssl_dp[i].command, argv) == 0)
		{
			temp = ft_strdup(g_ssl_dp[i].command);
			break ;
		}
	}
	if (ft_strcmp(temp, argv) != 0)
		error_message(argv);
	return (i);
}

void		data_input(int ac, t_ssl *ssl)
{
	char	*data;
	char	*temp;

	if ((ssl->flags.p == 1 || ac == 2) && get_next_line(0, &temp) > 0)
	{
		data = ft_strjoin(temp, "\n");
		free(temp);
		if (ssl->flags.p == 1)
			ft_printf("%s", data);
		ssl->dp.function(data);
		ft_putchar('\n');
		free(data);
	}
	else if ((ssl->flags.q == 2 || ac == 2) && get_next_line(0, &temp) > 0)
	{
		data = ft_strjoin(temp, "\n");
		free(temp);
		ssl->dp.function(data);
		ft_putchar('\n');
		free(data);
	}
}

void		ssl_input(int i, int ac, char *argv[], t_ssl *ssl)
{
	int		fd;
	char	*temp;

	data_input(ac, ssl);
	i = 0;
	while (argv[++i])
	{
		if (ft_strcmp(argv[i], "-s") == 0)
		{
			temp = ft_strdup(ssl->dp.command);
			if (!ssl->flags.q && !ssl->flags.r)
				ft_printf("%s (\"%s\") = ", ft_utoupper(temp), argv[i + 1]);
			ssl->dp.function(argv[i + 1]);
			print_by_flags(i, argv, ssl);
			free(temp);
		}
		else if ((fd = open(argv[i], O_RDONLY)) > 0)
		{
			get_file(fd, argv[i], ssl);
			if (argv[i + 1] != '\0')
				go_here(i, argv, ssl);
			break ;
		}
	}
}

int			main(int argc, char **argv)
{
	t_ssl	ssl;
	int		i;

	if (argc == 1)
	{
		error_usage();
		return (0);
	}
	i = 2;
	ssl.dp = g_ssl_dp[find_command(argv[1])];
	ft_bzero(&ssl.flags, sizeof(ssl.flags));
	while (argv[i])
	{
		if (*argv[i] == '-' && argv[i][1] != 's')
			get_flags(i, argc, argv, &ssl);
		if (argv[i][1] == 's')
			ssl.flags.s = 1;
		i++;
	}
	if (ssl.dp.command != NULL)
		ssl_input(i, argc, argv, &ssl);
	return (0);
}
