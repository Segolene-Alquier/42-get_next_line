/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:34:29 by salquier          #+#    #+#             */
/*   Updated: 2018/11/23 10:19:24 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;

	elem = *alst;
	if (*alst == NULL)
		return ;
	(*del)(elem->content, elem->content_size);
	free(elem);
	*alst = NULL;
}
