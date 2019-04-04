/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:14:49 by salquier          #+#    #+#             */
/*   Updated: 2018/11/24 22:38:29 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		positive;
	long	result;

	i = 0;
	positive = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			positive = -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		result = str[i] - 48;
		while (str[i + 1] >= '0' && str[i + 1] <= '9' && result >= 0)
			result = result * 10 + (str[i++ + 1] - 48);
		if (result < 0)
			return (positive == -1 ? 0 : -1);
		return (result * positive);
	}
	return (0);
}
