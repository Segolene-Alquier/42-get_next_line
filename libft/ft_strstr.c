/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:06:58 by salquier          #+#    #+#             */
/*   Updated: 2018/11/23 16:13:48 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*ptr_haystack;
	int		first;

	i = 0;
	ptr_haystack = (char *)haystack;
	if (!(ft_strlen(needle)))
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			first = i;
			while (haystack[i + j + 1] == needle[j + 1] && haystack[i + j + 1])
				j++;
			if (needle[j + 1] == '\0')
				return (&ptr_haystack[first]);
		}
		i++;
	}
	return (NULL);
}
