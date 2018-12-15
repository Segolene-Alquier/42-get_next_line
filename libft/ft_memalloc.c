/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:36:46 by salquier          #+#    #+#             */
/*   Updated: 2018/12/14 12:03:23 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem_area;

	if (size >= SIZE_MAX)
		return (NULL);
	if (!(mem_area = (void *)malloc(sizeof(*mem_area) * (size))))
		return (NULL);
	ft_bzero(mem_area, size);
	return (mem_area);
}
