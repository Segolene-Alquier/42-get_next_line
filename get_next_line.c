/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/11/28 19:32:46 by salquier         ###   ########.fr       */
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

char	*ft_realloc(char *old, int size)
{
	char *new;

	if (!old || !(new = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	printf("strncpy = %s\n", ft_strncpy(new, old, size));
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
			while (buf[i] != '\n' && buf[i] != '\0')
			{
				len += size;
				if (!(line[0] = ft_realloc(buf, len + 1)))
					return (-1);
				ft_strncat(line[0], buf, size);
				//printf("1 line[%d][%d] = %c\n", 0, letter, line[0][letter]);
				i++;
				letter++;
			}
			line[0][letter] = '\0';
			i++;
			//tmp = ft_strdup("\0");
			//len = 0;
			//printf("buf[%d] = %c\n", i, buf[i]);
			tmp = ft_strsub(buf, i, ft_strlen(buf) - i);
			/*while (buf[i])
			{
				printf("size = %lu, len = %lu\n", size, len);
				printf("buf[%d] = %c\n", i, buf[i]);
				len+= size;
				if (!(tmp = ft_realloc(buf, len + 1)))
					return (-1);
				printf("strncat = %s\n", ft_strncat(tmp, buf, size));
				//tmp = (char *)malloc(sizeof(char) * (j + 1));
				//tmp[j] = buf[i];
				//printf("tmp[%d] = %c\n", j, tmp[j]);
				j++;
				i++;
			}*/
			printf("tmp : %s\n", tmp);
			printf("line[0] : %s\n", line[0]);
		}
	}
	else
	{
		printf("%s\n", "----- TMP existant / PAS 1ere LIGNE -----");
		printf("tmp[%d] = %c\n", j, tmp[j]);
		while (tmp[i])
		{
			while (tmp[i] != '\n')
			{
				len++;
				if (!(line[0] = ft_realloc(tmp, len + 1)))
					return (-1);
				ft_strncat(line[0], tmp, len);
				printf("2 line[%d][%d] = %c\n", 0, letter, line[0][letter]);
				i++;
				letter++;
			}
			line[0][letter] = '\0';
			i++;
			while (tmp[i])
			{
			tmp = (char *)malloc(sizeof(char) * (j + 1));
			tmp[j] = tmp[i];
			//printf("tmp[%d] = %c\n", j, tmp[j]);
			j++;
			i++;
			}
			printf("tmp : %s\n", tmp);
			printf("line[0] : %s\n", line[0]);
		}
	}
	if (!tmp)
	{
		printf("%s\n", "----- DERNIERE LIGNE -----");
		return (0);
	}
	return (1);
}


int		main(void)
{
	int fd;
	char **line;
	//int i = 0;
	line = (char **)malloc(sizeof(char *) * 1000);
	//line = NULL;
	fd = open("test", O_RDONLY);
	printf("appel 1 : %d\n", get_next_line(fd, line));
	//printf("line[0] : %s\n", line[0]);
	printf("appel 2 : %d\n", get_next_line(fd, line));
	//printf("line[1] : %s\n", line[0]);
	printf("appel 3 : %d\n", get_next_line(fd, line));
	//printf("line[2] : %s\n", line[0]);

	close(fd);
	return (0);
}
