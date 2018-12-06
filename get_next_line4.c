/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/12/05 15:09:39 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

char	*read_file(const int fd)
{
	char	buf[BUFF_SIZE + 1];
	size_t	size;
	char	*bufcpy;

	bufcpy = ft_strnew(BUFF_SIZE);
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		//printf("%s\n", "---- READING ----");
		bufcpy = ft_strjoin(bufcpy, buf);
		//printf("size : %lu\n", size);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (bufcpy);
}

int		get_next_line(const int fd, char **line)
{
	char		*buffer;
	char		*bufcpy;
	static char	*tmp = NULL;
	int			i;

	i = 0;
	line[0] = ft_strdup("\0");
	bufcpy = ft_strdup("\0");
	buffer = NULL;
	if (fd == -1 || !line)
		return (-1);
	if (!tmp || (tmp && !ft_strchr(tmp, '\n')))
	{
		bufcpy = read_file(fd);
		buffer = ft_strdup(bufcpy);
	}
	if (tmp)
	{
		//printf("tmp : %s\n", tmp);
		if (!(ft_strncat(tmp, bufcpy, ft_strlen(bufcpy))))
			return (-1);
		//printf("tmp 2 : %s\n", tmp);
		buffer = ft_strdup(tmp);
	}
	//printf("buffer : %s\n", buffer);
	while (buffer[i] != '\n' && buffer[i])
		i++;

	//printf("len bufcpy : %lu\n", ft_strlen(bufcpy));
	if (!(line[0] = ft_strsub(buffer, 0, i)) || !(tmp = ft_strsub(buffer, i + 1, ft_strlen(buffer))))
		return (-1);
	//printf("tmp final : %s\n", tmp);
	//fflush(stdout);
	if (!ft_strlen(tmp))
		return (0);
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
	printf("line[0] : %s\n--------------------\n", line[0]);
	printf("appel 2 : %d\n", get_next_line(fd, line));
	printf("line[0] : %s\n--------------------\n", line[0]);
	printf("appel 3 : %d\n", get_next_line(fd, line));
	printf("line[0] : %s\n--------------------\n", line[0]);
	printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("line[2] : %s\n", line[0]);
	//printf("appel 4 : %d\n", get_next_line(fd, line));
	/*printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));*/

	close(fd);
	return (0);
}
