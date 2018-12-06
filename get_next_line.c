/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/12/06 18:09:44 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
char	*read_file(const int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		size;
	char	*bufcpy;

	bufcpy = ft_strnew(BUFF_SIZE);
	//printf("bufcpy : %s\n", bufcpy);
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
	if ((!tmp || (tmp && !ft_strchr(tmp, '\n'))))
	{
		//printf("tmp : %s\n", tmp);
	//	printf("bufcpy 1 : %s\n", bufcpy);
		// ne doit pqs pqsser pqr cette condition quand tmp contient un \0 et pas de \n
		// pb : ma fonction renvoie 0 car bufcpy == '\0', alors que tmp est existant
		bufcpy = read_file(fd);
		//printf("bufcpy 2 : %s\n", bufcpy);
		//if (ft_strequ(bufcpy, "\0"))
		//	return (0);
	}
	if (ft_strequ(bufcpy, "\0") && ft_strequ(tmp, "\0"))
		return (0);

	buffer = fill_buffer(tmp, bufcpy);
	//printf("buffer : %s\n", buffer);
	//	printf("tmp : %s\n", tmp);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!(line[0] = ft_strsub(buffer, 0, i)) 
			|| !(tmp = ft_strsub(buffer, i + 1, ft_strlen(buffer))))
		return (-1);
	//printf("line[0] : %s\n", line[0]);
	//printf("tmp final : %s\n", tmp);
	return (1);
}

/*int	main(void)
{
	char     *line;
	int        out;
	int        p[2];
	char     *str;
	int        gnl_ret;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
  printf("gnl_ret : %d\n", gnl_ret = get_next_line(p[0], &line));
  printf("ine : %s\n", line);



}*/


/*int		main(void)
  {
  char *line;
  int		out;
  int p[2];
  int fd;
  int gnl_ret;

  fd = 1;
  out = dup(fd);
  pipe(p);
  dup2(p[1], fd);
  write(fd, "aaa", 3);
  close(p[1]);
  dup2(out, fd);
  printf("fd : %d\n", fd);
  printf("p[0] : %d\n", p[0]);
  printf("p[1] : %d\n", p[1]);
  printf("out : %d\n", out);
  fflush(stdout);
 
  printf("gnl_ret : %d\n", gnl_ret = get_next_line(p[0], &line));
  printf("p[0] : %d\n", p[0]);
  printf("p[1] : %d\n", p[1]);
  printf("ine : %s\n", line);
//mt_assert(strcmp(line, "aaa") == 0);
//mt_assert(gnl_ret == 0 || gnl_ret == 1);

}*/

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
//printf("appel 4 : %d\n", get_next_line(fd, line));
//printf("line[0] : %s\n", line[0]);
//printf("appel 4 : %d\n", get_next_line(fd, line));
//printf("appel 4 : %d\n", get_next_line(fd, line));
//printf("appel 4 : %d\n", get_next_line(fd, line));
//printf("appel 4 : %d\n", get_next_line(fd, line));

close(fd);
return (0);
}*/
