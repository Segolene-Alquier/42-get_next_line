/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:04:43 by salquier          #+#    #+#             */
/*   Updated: 2018/11/09 17:34:02 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr_s;

	i = 0;
	ptr_s = (char *)s;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&ptr_s[i]);
		i++;
	}
	if (c == '\0')
		return (&ptr_s[i]);
	return (NULL);
}
