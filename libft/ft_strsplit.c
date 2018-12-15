/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:08:39 by salquier          #+#    #+#             */
/*   Updated: 2018/11/23 16:56:50 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words_ctr(char const *s, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				word++;
		}
		i++;
	}
	return (word);
}

static int		ltr_c(char const *s, char c, int start)
{
	int letter;

	letter = 0;
	while (s[start] != c && s[start])
	{
		start++;
		letter++;
	}
	return (letter);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		word;
	int		letter;

	i = 0;
	word = 0;
	if (!s || !(tab = (char **)malloc(sizeof(char *) * (words_ctr(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		letter = 0;
		while (s[i] == c)
			i++;
		if (!(tab[word] = (char *)malloc(sizeof(char) * (ltr_c(s, c, i) + 1))))
			return (NULL);
		while (s[i] && s[i] != c)
			tab[word][letter++] = s[i++];
		tab[word][letter] = '\0';
		word++;
	}
	tab[words_ctr(s, c)] = 0;
	return (tab);
}
