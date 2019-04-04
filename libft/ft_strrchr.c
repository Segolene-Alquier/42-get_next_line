/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:35:19 by salquier          #+#    #+#             */
/*   Updated: 2018/11/09 17:54:35 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr_s;

	i = ft_strlen(s);
	ptr_s = (char *)s;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&ptr_s[i]);
		i--;
	}
	return (NULL);
}
