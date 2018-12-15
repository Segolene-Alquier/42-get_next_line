/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:28:26 by salquier          #+#    #+#             */
/*   Updated: 2018/11/24 13:27:15 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*buffer;
	t_list	*begin;

	if (!lst)
		return (NULL);
	buffer = (*f)(lst);
	if (!(newlst = ft_lstnew(buffer->content, buffer->content_size)))
		return (NULL);
	begin = newlst;
	lst = lst->next;
	while (lst != NULL)
	{
		buffer = (*f)(lst);
		if (!(newlst->next = ft_lstnew(buffer->content, buffer->content_size)))
			return (NULL);
		lst = lst->next;
		newlst = newlst->next;
	}
	newlst->next = NULL;
	return (begin);
}
