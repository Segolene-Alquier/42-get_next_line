/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/12/05 10:43:02 by salquier         ###   ########.fr       */
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
		printf("%s\n", "---- READING ----");
		bufcpy = ft_strjoin(bufcpy, buf);
		//printf("size : %lu, len : %lu\n", size, len);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (bufcpy);
}

int		get_next_line(const int fd, char **line)
{
	char		*bufcpy;
	static char	*tmp = NULL;
	int			i;

	i = 0;
	line[0] = ft_strdup("\0");
	bufcpy = NULL;
	if (fd == -1 || !line)
		return (-1);
	if (tmp)
	{
		if (!ft_strchr(tmp, '\n'))
			bufcpy = read_file(fd);
		ft_strncat(tmp, bufcpy, ft_strlen(bufcpy));
		while (tmp[i] && tmp[i] != '\n')
			i++;
		if (!(line[0] = ft_strsub(tmp, 0, i)) || !(tmp = ft_strsub(tmp, i + 1, ft_strlen(bufcpy))))
			return (-1);
		if (!ft_strlen(tmp))
			return (0);
		if (line[0])
			return (1);
	}
	if (!tmp)
	{
		bufcpy = read_file(fd);
		while (bufcpy[i] != '\n' && bufcpy[i])
			i++;
		if (!(line[0] = ft_strsub(bufcpy, 0, i)) || !(tmp = ft_strsub(bufcpy, i + 1, ft_strlen(bufcpy))))
			return (-1);
		if (!ft_strlen(tmp))
			return (0);
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
	printf("line[2] : %s\n", line[0]);
	//printf("appel 4 : %d\n", get_next_line(fd, line));
	/*printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));*/

	close(fd);
	return (0);
}
