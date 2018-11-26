/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/11/26 13:32:29 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE];
	int		size;
	int i;

	i = 0;
	size = BUFF_SIZE;
	line = NULL;
	if (fd == -1)
		return (1);
	while (i < size)
	{
		if (buf[i] != '\n')
		{
			size = read(fd, buf+i, 1);
			printf("buf[%d] = %c\n", i, buf[i]);
			i++;
		}
		else
			return (123);
	}
	buf[size] = 0;
	write(1, buf, size);
	return (0);
}


int		main(void)
{
	int fd;
	char **line;
	line = NULL;
	fd = open("test", O_RDONLY);
	printf("%d\n", get_next_line(fd, line));
	close(fd);
	return (0);
}
