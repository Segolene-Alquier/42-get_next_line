/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:42:35 by salquier          #+#    #+#             */
/*   Updated: 2018/11/23 16:08:21 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	unsigned long	j;
	char			*ptr_s1;
	char			*ptr_s2;

	ptr_s1 = (char *)s1;
	ptr_s2 = (char *)s2;
	i = ft_strlen(s1);
	j = 0;
	while ((j < n) && s2[j])
	{
		ptr_s1[i] = ptr_s2[j];
		i++;
		j++;
	}
	ptr_s1[i] = '\0';
	return (s1);
}
