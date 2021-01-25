/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:35:24 by jinpark           #+#    #+#             */
/*   Updated: 2019/03/02 19:27:09 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define MAX_FD 10000

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int new_line(char **s, char **line, int fd);
int	get_next_line(const int fd, char **line);

#endif
