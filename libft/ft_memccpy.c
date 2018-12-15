/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:24:22 by salquier          #+#    #+#             */
/*   Updated: 2018/11/23 16:05:08 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned char	*ptr_src;
	size_t			i;
	unsigned char	ccpy;

	i = 0;
	ptr_src = (unsigned char *)s;
	ccpy = (unsigned char)c;
	while (i < n)
	{
		ft_memset(&d[i], ptr_src[i], 1);
		if (ccpy == ptr_src[i])
			return (&d[i + 1]);
		i++;
	}
	return (NULL);
}
