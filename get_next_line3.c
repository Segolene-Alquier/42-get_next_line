/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/12/01 17:58:52 by salquier         ###   ########.fr       */
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
	static char *tmp = NULL;
	char buf[BUFF_SIZE + 1];
	int letter;
	int i;
	size_t	len;
	size_t	size;
	int j;
	//char *bufcpy;

	j = 0;
	i = 0;
	len = 0;
	letter = 0;
	if (fd == -1 || !line)
		return (-1);
	line[0] = ft_strdup("\0");
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		printf("size = %lu\n", size);
		buf[size] = '\0';
		while (buf[i] && !tmp)
		{
			printf("%s\n", "---- TMP NON-EXISTANT ----");
			if (buf[i] == '\n')
				break ;
			printf("buf[%d] :%c\n", i, buf[i]);
			//j'enregistre dans line
			i++;
		}
		printf("nbuf[%d] :%c\n", i, buf[i]);
		while (tmp[i])
		{
			printf("%s\n", "---- TMP EXISTANT ----");
			if(!ft_strchr(tmp, '\n'))
				break ;
			// j'enregistre dans line
			i++;
		}
		if (buf[i] == '\n' && (i + 1) < (int)size)
		{
			printf("%s\n", "---- TMP A REMPLIR ----");
			//j'enregistre dans tmp le reste
		}
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
