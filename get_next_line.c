/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/11/26 19:03:48 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

/*int		get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE + 1];
	int i;
	int newline;
	int letter;

	i = 0;
	line = NULL;
	newline = 0;
	if (fd == -1)
		return (1);
	while (buf[i] != EOF)
	{
		letter = 0;
		line = (char **)malloc(sizeof(char *) * (newline + 1));
		while (read(fd, buf+i, 1) && buf[i] != '\n')
		{
			line[newline] = (char *)malloc(sizeof(char) * (letter + 1));
			line[newline][letter] = buf[i];
			printf("buf[%d] = %c\n", i, buf[i]);
			printf("newline[%d][%d] = %c\n", newline, letter, line[newline][letter]);
			i++;
			letter++;
		}
		i++;
		newline++;
	}
	buf[i] = 0;
	//write(1, buf, size);
	return (0);
}*/
/*int		get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE + 1];
	static int i;
	int newline;
	int letter;
	char *tmp;

	i = 0;
	//line = NULL;
	newline = 0;
	if (fd == -1)
		return (1);
	while (read(fd, buf+i, BUFF_SIZE))
	{
		printf("buf[%d] = %c\n", i, buf[i]);
		letter = 0;
		line = (char **)malloc(sizeof(char *) * (newline + 1));
		while (buf[i] != '\n')
		{
			line[newline] = (char *)malloc(sizeof(char) * (letter + 1));
			line[newline][letter] = buf[i];
			printf("buf[%d] = %c\n", i, buf[i]);
			printf("newline[%d][%d] = %c\n", newline, letter, line[newline][letter]);
			i++;
			letter++;
		}
		i++;
		printf("i = %d\n", i);
		newline++;
	}
	line[newline] = 0;
	return (0);
}*/
int		get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE + 1];
	static int i;
	//int newline;
	//int letter;
	char *tmp;
	size_t size;

	i = 0;
	line = NULL;
	//newline = 0;
	if (fd == -1)
		return (1);
	// GET NB OF BYTES IN FILE VIA READ //
	tmp = ft_strnew(size = read(fd, buf+i, BUFF_SIZE));
	// ALLOCATE SUFFICIENT MEMORY //
	//tmp = ft_strnew(size);
	// COPY TEXT IN BUFFER //
	printf("size = %lu\n", size);
	printf("tmp[74] = %c\n", tmp[77]);
	i = 0;
	while (read(fd, buf+i, BUFF_SIZE))
	{
		tmp[i] = buf[i];
		printf("buf[%d] = %c\n", i, buf[i]);
		printf("tmp[%d] = %c\n", i, tmp[i]);

		i++;
	}
		/*letter = 0;
		line = (char **)malloc(sizeof(char *) * (newline + 1));
		while (buf[i] != '\n')
		{
			line[newline] = (char *)malloc(sizeof(char) * (letter + 1));
			line[newline][letter] = buf[i];
			printf("buf[%d] = %c\n", i, buf[i]);
			printf("newline[%d][%d] = %c\n", newline, letter, line[newline][letter]);
			i++;
			letter++;
		}
		i++;
		printf("i = %d\n", i);
		newline++;
	}
	line[newline] = 0;*/
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
