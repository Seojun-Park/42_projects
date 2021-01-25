/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_link.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:53:44 by jinpark           #+#    #+#             */
/*   Updated: 2019/06/26 14:16:30 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*get_append(t_gnl_link *gnl)
{
	int			i;
	
	i = 0;
	gnl->nl = 0;
	while (gnl->i + i < gnl->count)
	{
		if (gnl->buf[gnl->i + i] == '\n')
		{
			gnl->nl = 1;
			i++;
			break ;
		}
		i++;
	}
	gnl->i += i;
	return (ft_strsub(gnl->buf, gnl->i - i, i - gnl->nl));
}

static t_gnl_link	*get_gnl(t_list **lst, int fd)
{
	t_gnl_link	*gnl;
	t_list		*temp;

	temp = *lst;
	while (temp)
	{
		gnl = (t_gnl_link *)(temp->content);
		if (gnl->fd == fd)
			return (gnl);
		temp = temp->next;
	}
	gnl = (t_gnl_link *)ft_memalloc(sizeof(t_gnl_link));
	gnl->buf = ft_strnew(BUFF_SIZE);
	gnl->count = BUFF_SIZE;
	gnl->i = BUFF_SIZE;
	gnl->fd = fd;
	gnl->nl = 1;
	temp = ft_lstnew(gnl, sizeof(t_gnl_link));
	ft_memdel((void **)&gnl);
	ft_lstadd(lst, temp);
	return ((t_gnl_link *)(temp->content));
}

static void 		del_gnl(t_list **lst, int fd, char **str)
{
	t_gnl_link	*gnl;
	t_list		**temp;
	t_list		*ptr;

	temp = lst;
	while (*temp)
	{
		gnl = (t_gnl_link *)((*temp)->content);
		if (gnl->fd == fd)
			break ;
		*temp = ((*temp)->next);
	}
	if (*temp)
	{
		ptr = (*temp)->next;
		ft_strdel(&(gnl->buf));
		ft_memdel((void **)&gnl);
		ft_memdel((void **)temp);
		*temp = ptr;
	}
	ft_strdel(str);
}

static int			read_buffer(t_gnl_link *gnl, t_list **lst, char **temp, char **line)
{
	if (gnl->i == gnl->count)
	{
		gnl->count = read(gnl->fd, gnl->buf, BUFF_SIZE);
		if (gnl->count == -1)
		{
			del_gnl(lst, gnl->fd, temp);
			return (-1);
		}
		gnl->i = 0;
		if (gnl->count == 0)
		{
			if (gnl->nl == 0)
			{
				*line = *temp;
				return (1);
			}
		}
	}
	return (0);
}

int					get_next_line_link(int const fd, char **line)
{
	static	t_list		*lst;
	t_gnl_link			*gnl;
	char				*temp;
	int					ret;

	if (fd < 0 || line == NULL)
		return (-1);
	gnl = get_gnl(&lst, fd);
	temp = ft_strnew(0);
	while (gnl->count > 0)
	{
		if ((ret = read_buffer(gnl, &lst, &temp, line)) != 0)
			return (ret);
		while (gnl->i < gnl->count)
		{
			temp = ft_strmerge(temp, get_append(gnl));
			if (gnl->nl)
			{
				*line = temp;
				return (1);
			}
		}
	}
	del_gnl(&lst, fd, &temp);
	return (0);
}
