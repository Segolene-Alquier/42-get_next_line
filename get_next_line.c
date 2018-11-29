/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/11/29 15:25:02 by salquier         ###   ########.fr       */
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
/*char	*cpy_file(int fd)
{
	char buf[BUFF_SIZE + 1];
	char *tmp;
	size_t size;
	size_t len;
	len = 0;
	tmp = ft_strdup("\0");
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		len += size;
		if (!(tmp = ft_realloc(tmp, len + 1)))
			return (NULL);
		ft_strncat(tmp, buf, size);
	}
	return (tmp);
}*/
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
	if (!tmp)
	{
		printf("%s\n", "----- TMP non existant / 1ere LIGNE -----");
		while ((size = read(fd, buf, BUFF_SIZE) > 0))
		{
			//printf("size = %lu\n", size);
			while (buf[i] != '\n' && buf[i] != '\0')
			{
				len += size;
			//printf("size = %lu\n", size);
				if (!(line[0] = ft_realloc(buf, len + 1)))
					return (-1);
				ft_strncat(line[0], buf, size);
			//printf("ft_strlen(buf) = %lu\n", ft_strlen(buf));
				//printf("1 line[%d][%d] = %c\n", 0, letter, line[0][letter]);
				i++;
				letter++;
			}
			line[0][letter] = '\0';
			i++;
			tmp = ft_strsub(buf, i, ft_strlen(buf) - i);
			//printf("i = %d\n", i);
			//tmp[ft_strlen(buf) - i] = '\0';
			printf("line[0] : %s\n", line[0]);
			printf("tmp : %s\n", tmp);
			//printf("buf : %s\n", buf);
		}
	}
	else
	{
		printf("%s\n", "----- TMP existant / PAS 1ere LIGNE -----");
		while (tmp[i] != '\n')
		{
				len++;
				if (!(line[0] = ft_realloc(tmp, len + 1)))
					return (-1);
				ft_strncat(line[0], tmp, len);
				//printf("2 line[%d][%d] = %c\n", 0, letter, line[0][letter]);
				i++;
				letter++;
		}
		line[0][letter] = '\0';
		i++;
		bufcpy = ft_strsub(tmp, i, ft_strlen(tmp) - i);
		ft_strcpy(tmp, bufcpy);
		printf("line[0] : %s\n", line[0]);
		printf("tmp : %s\n", tmp);
		if (tmp[i] == EOF)
		{
			printf("%s\n", "----- DERNIERE LIGNE -----");
			return (0);
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
	//printf("line[0] : %s\n", line[0]);
	printf("appel 2 : %d\n", get_next_line(fd, line));
	//printf("line[1] : %s\n", line[0]);
	printf("appel 3 : %d\n", get_next_line(fd, line));
	//printf("line[2] : %s\n", line[0]);
	//printf("appel 4 : %d\n", get_next_line(fd, line));
	/*printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));*/

	close(fd);
	return (0);
}
