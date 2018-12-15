/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:32:48 by salquier          #+#    #+#             */
/*   Updated: 2018/12/14 12:50:24 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		start;
	int		i;
	char	*newstr;

	if (!s1 || !s2 || !(newstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	start = ft_strlen(s1);
	ft_strcpy(newstr, s1);
	i = 0;
	while (s2[i])
	{
		newstr[start] = s2[i];
		start++;
		i++;
	}
	newstr[start] = '\0';
	return (newstr);
}
