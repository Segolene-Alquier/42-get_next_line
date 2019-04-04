/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:50:36 by salquier          #+#    #+#             */
/*   Updated: 2018/11/22 19:33:28 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*elem;

	elem = *alst;
	while (elem != NULL)
	{
		(*del)(elem->content, elem->content_size);
		free(elem);
		elem = elem->next;
	}
	*alst = NULL;
}
