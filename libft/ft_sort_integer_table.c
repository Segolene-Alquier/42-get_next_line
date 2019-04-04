/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:58:11 by salquier          #+#    #+#             */
/*   Updated: 2018/11/24 11:51:04 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int i;
	int buffer;

	i = 0;
	if (!tab)
		return ;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			buffer = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buffer;
			i = 0;
		}
		else
			i++;
	}
}
