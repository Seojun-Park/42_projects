/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:17:10 by jinpark           #+#    #+#             */
/*   Updated: 2019/02/19 21:27:39 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *tail;

	head = NULL;
	tail = NULL;
	while (lst != NULL)
	{
		if (tail == NULL)
		{
			tail = f(lst);
			if (tail == NULL)
				return (NULL);
			head = tail;
		}
		else
		{
			tail->next = f(lst);
			if (tail->next == NULL)
				return (NULL);
			tail = tail->next;
		}
		lst = lst->next;
	}
	return (head);
}
