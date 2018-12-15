/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occurence_chr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:19:33 by salquier          #+#    #+#             */
/*   Updated: 2018/11/24 11:56:41 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_occurence_chr(char c, char *str)
{
	int i;
	int ischar;

	i = 0;
	ischar = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			ischar++;
		i++;
	}
	return (ischar);
}
