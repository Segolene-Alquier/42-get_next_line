/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/12/13 14:00:28 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

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

char	*fill_buffer(char *tmp, char *bufcpy)
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

t_list	*find_create_lst(t_list **tmp_lst, const int fd)
{
	t_list	*lst;
	t_list	*new_lst;
	t_list	*head;

	lst = *tmp_lst;
	head = *tmp_lst;
	while (lst)
	{
		if ((int)lst->content_size == fd)
			break ;
		lst = lst->next;
	}
	if (lst == NULL)
	{
		new_lst = ft_lstnew("\0", fd);
		ft_lstadd(tmp_lst, new_lst);
		lst = new_lst;
	}
	return (lst);
}

int		get_next_line(const int fd, char **line)
{
	char			*buffer;
	char			*bufcpy;
	t_list			*lst;
	static t_list	*head = NULL;
	int				i;

	i = 0;
	lst = NULL;
	bufcpy = ft_strdup("\0");
	if (BUFF_SIZE < 1 || fd < 0 || !line || (read(fd, bufcpy, 0) < 0))
		return (-1);
	lst = find_create_lst(&head, fd);
	line[0] = ft_strdup("\0");
	if ((!lst->content || (lst->content && !ft_strchr(lst->content, '\n'))))
		bufcpy = read_file(fd);
	if (ft_strequ(bufcpy, "\0") && ft_strequ(lst->content, "\0"))
		return (0);
	buffer = fill_buffer(lst->content, bufcpy);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!(line[0] = ft_strsub(buffer, 0, i))
		|| !(lst->content = ft_strsub(buffer, i + 1, ft_strlen(buffer))))
		return (-1);
	return (1);
}
