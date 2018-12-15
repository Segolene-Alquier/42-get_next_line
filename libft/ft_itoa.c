/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:11:40 by salquier          #+#    #+#             */
/*   Updated: 2018/11/23 16:57:21 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length_nb(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	len = length_nb(n);
	i = length_nb(n) - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		len = length_nb(n) + 1;
		i = length_nb(n);
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (len == length_nb(n) + 1)
		str[0] = '-';
	while (i >= 0 && str[i] != '-')
	{
		str[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
