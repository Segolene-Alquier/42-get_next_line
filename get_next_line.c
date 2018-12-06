/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/12/06 14:16:35 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

char	*read_file(const int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		size;
	char	*bufcpy;

	bufcpy = ft_strnew(BUFF_SIZE);
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		bufcpy = ft_strjoin(bufcpy, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (bufcpy);
}

char	*fill_buffer(char * tmp, char *bufcpy)
{
	char *buffer;

	if (!tmp || (tmp && !ft_strchr(tmp, '\n')))
	{
		if (!(buffer = ft_strdup(bufcpy)))
			return (NULL);
	}
	if (tmp)
	{
		if (!(ft_strncat(tmp, bufcpy, ft_strlen(bufcpy))) 
			|| !(buffer = ft_strdup(tmp)))
			return (NULL);
	}
	return (buffer);
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
	//buffer = NULL;
	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, bufcpy, 0) < 0)
		return (-1);
	if (!tmp || (tmp && !ft_strchr(tmp, '\n')))
	{
		bufcpy = read_file(fd);
		if (ft_strequ(bufcpy, "\0"))
			return (0);
	}
	buffer = fill_buffer(tmp, bufcpy);
	//printf("buffer : %s\n", buffer);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!(line[0] = ft_strsub(buffer, 0, i)) 
		|| !(tmp = ft_strsub(buffer, i + 1, ft_strlen(buffer))))
		return (-1);
	return (1);
}


/*int		main(int argc, char **argv)
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
	printf("line[0] : %s\n", line[0]);
	//printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));

	close(fd);
	return (0);
}*/
