/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/11/30 19:31:59 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

char	*ft_realloc(char *old, int size)
{
	char *new;

	if (!old || !(new = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strncpy(new, old, size);
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static char *tmp;
	char buf[BUFF_SIZE + 1];
	int letter;
	int i;
	size_t	len;
	size_t	size;
	int j;
	char *bufcpy;

	j = 0;
	i = 0;
	len = 0;
	letter = 0;
	if (fd == -1 || !line)
		return (-1);
	line[0] = ft_strdup("\0");
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (tmp)
		{
			while (tmp[i])
			{
				while (tmp[i] != '\n' && tmp[i])
				{
					j'enregistre dans line
					i++;
				}
				if (tmp[i] == '\n')
				{
					j'enregistre dans tmp le reste
					return (1)
				}
			}
		}
		while (buf[i] != '\n' && buf[i])
		{
			if (!tmp)
				j'enregistre dans line ce que je trouve
			else
				j'enregistre dans bufcpy ce aue je lis
			i++;
		}
		if (!tmp)
			j'enregistre dans tmp ce qu'il y a apres le \n
		else
			je concatene bufcpy avec tmp;
	}
	return (1);
}


int		main(int argc, char **argv)
{
	int fd;
	char **line;
	//int i = 0;
	if (argc < 0)
		return (0);
	line = (char **)malloc(sizeof(char *) * 1000);
	fd = open(argv[1], O_RDONLY);
	printf("appel 1 : %d\n", get_next_line(fd, line));
	printf("line[0] : %s\n", line[0]);
	printf("appel 2 : %d\n", get_next_line(fd, line));
	printf("line[0] : %s\n", line[0]);
	printf("appel 3 : %d\n", get_next_line(fd, line));
	printf("line[0] : %s\n", line[0]);
	printf("appel 4 : %d\n", get_next_line(fd, line));
	//printf("line[2] : %s\n", line[0]);
	//printf("appel 4 : %d\n", get_next_line(fd, line));
	/*printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));*/

	close(fd);
	return (0);
}
