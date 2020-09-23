/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:57:47 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/22 12:26:06 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*res;
	t_list		*tmp;
	t_list		*first;

	tmp = (*f)(lst);
	if (!(res = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	first = res;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		if (!(res->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst = lst->next;
		res = res->next;
	}
	return (first);
}
