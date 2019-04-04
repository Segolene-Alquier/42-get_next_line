/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:19:27 by salquier          #+#    #+#             */
/*   Updated: 2018/11/10 17:18:37 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < (n - 1))
	{
		if (ptr_s1[i] != ptr_s2[i])
			return ((int)ptr_s1[i] - (int)ptr_s2[i]);
		i++;
	}
	if (ptr_s1[i] != ptr_s2[i])
		return ((int)ptr_s1[i] - (int)ptr_s2[i]);
	return (0);
}
