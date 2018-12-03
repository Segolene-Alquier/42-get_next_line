/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/12/03 21:09:59 by salquier         ###   ########.fr       */
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

char	*read_file(const int fd)
{
	char	buf[BUFF_SIZE + 1];
	size_t	len;
	size_t	size;
	char	*bufcpy;

	len = 0;
	bufcpy = ft_strnew(BUFF_SIZE);
	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		len += size;
		buf[size] = '\0';
		printf("%s\n", "---- TMP NON-EXISTANT ----");
		if (!(bufcpy = ft_realloc(bufcpy, len)))
			return (NULL);
		ft_strncat(bufcpy, buf, len + 1);
		//printf("size : %lu, len : %lu\n", size, len);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (bufcpy);
}


int		get_next_line(const int fd, char **line)
{
	int			j;
	char		*bufcpy;
	static char	*tmp = NULL;
	int			i;

	j = 0;
	i = 0;
	line[0] = ft_strdup("\0");
	if (fd == -1 || !line)
		return (-1);
	bufcpy = read_file(fd);
	printf("bufcpy : %s\n", bufcpy);
	while (bufcpy && bufcpy[i] != '\n')
		i++;
	printf("bufcpy[%d] : %c\n", i, bufcpy[i]);
	if (!(line[0] = ft_strsub(bufcpy, 0, i)) || !(tmp = ft_strsub(bufcpy, i + 1, ft_strlen(bufcpy))))
		return (-1);

	printf("ft_strlen(bufcpy): %lu\n", ft_strlen(bufcpy));
	/*while (tmp && tmp[i])
	{
		printf("%s\n", "---- TMP EXISTANT ----");
		if (!ft_strchr(tmp, '\n'))
			// call read;
		i++;
	}*/
	/*if (!(line[0] = ft_strsub(tmp, 0, i)) || 
		!(tmp = ft_strsub(bufcpy, i + 1, ft_strlen(bufcpy - 1)))
		return (-1);*/

	//line[0][i] = '\0';
	printf("line[0] : %s\n", line[0]);
	printf("tmp : %s\n", tmp);

	
		//printf("buf[%d] :%c\n", i, buf[i]);
	/*if (buf[i] == '\n' && len < size)
		{
			printf("%s\n", "---- TMP A REMPLIR ----");
			if (!(tmp = ft_strsub(buf, i + 1, size - i + 1)))
				return (-1);
			tmp[size - i + 2] = '\0';
		}
	}
	printf("tmp con tes morts : %s\n", tmp);
		//printf("nbuf[%d] :%c\n", i, buf[i]);*/
		/*while (tmp && tmp[i])
		{
			printf("%s\n", "---- TMP EXISTANT ----");
			if(!(line[0] = ft_realloc(tmp, len + 1)))
				return (-1);
			if(ft_strchr(tmp, '\n'))
				break ;
			i++;
			len++;
		}
		line[0][i] = '\0';
		//printf("buf[%d] :%c\n", i, buf[i]);
		printf("line[0] : %s\n", line[0]);
		printf("tmp : %s\n", tmp);*/
		/*if (tmp[i] == '\n' && len < size)
		{
			printf("%s\n", "---- TMP A REMPLIR ----");
			//j'enregistre dans tmp le reste // strsub
		}*/
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
	printf("line[0] : %s\n", line[0]);
	//printf("appel 3 : %d\n", get_next_line(fd, line));
	//printf("line[0] : %s\n", line[0]);
	//printf("appel 4 : %d\n", get_next_line(fd, line));
	//printf("line[2] : %s\n", line[0]);
	//printf("appel 4 : %d\n", get_next_line(fd, line));
	/*printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));
	printf("appel 4 : %d\n", get_next_line(fd, line));*/

	close(fd);
	return (0);
}
