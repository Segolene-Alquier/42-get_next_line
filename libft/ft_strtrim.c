/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:24:45 by salquier          #+#    #+#             */
/*   Updated: 2018/11/23 16:57:47 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_word_after(char const *s, int i)
{
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	str = NULL;
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	while (s[i])
	{
		if (is_word_after(s, i))
			j++;
		i++;
	}
	if (!(str = ft_strsub(s, start, j)))
		return (NULL);
	return (str);
}
