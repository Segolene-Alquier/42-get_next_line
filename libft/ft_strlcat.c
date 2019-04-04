/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:31:30 by salquier          #+#    #+#             */
/*   Updated: 2018/11/23 16:07:15 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	len_dst;

	i = ft_strlen(dst);
	len_dst = i;
	j = 0;
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	while ((j < (size - len_dst - 1)) && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + len_dst);
}
