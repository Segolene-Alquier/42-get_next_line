/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:33:02 by salquier          #+#    #+#             */
/*   Updated: 2018/11/24 23:28:37 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*ptr_haystack;
	unsigned long	i;
	unsigned long	j;
	int				first;

	i = 0;
	j = 0;
	ptr_haystack = (char *)haystack;
	if (!(ft_strlen(needle)) || ft_strequ(haystack, needle))
		return ((char *)haystack);
	while (haystack[i] && (i + j) < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			first = i;
			while ((haystack[i + j + 1] == needle[j + 1])
					&& ((i + j + 1) < len) && needle[j + 1] != '\0')
				j++;
			if (needle[j + 1] == '\0')
				return (&ptr_haystack[first]);
		}
		i++;
	}
	return (NULL);
}
