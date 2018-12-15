/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word_after.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:00:30 by salquier          #+#    #+#             */
/*   Updated: 2018/11/24 11:49:31 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_word_after(int index, char *str)
{
	if (!(ft_strlen(str)))
		return (0);
	while (str[index])
	{
		if (str[index] == ' ' || str[index] == '\t')
			index++;
		else
			return (1);
	}
	return (0);
}
