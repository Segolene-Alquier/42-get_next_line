/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:38:31 by salquier          #+#    #+#             */
/*   Updated: 2018/11/09 13:43:13 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1bis;
	unsigned char	*s2bis;

	i = 0;
	s1bis = (unsigned char *)s1;
	s2bis = (unsigned char *)s2;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1bis[i] - s2bis[i]);
		i++;
	}
	if (s2[i])
		return (s1bis[i] - s2bis[i]);
	return (0);
}
