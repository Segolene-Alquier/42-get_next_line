/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salquier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:40:50 by salquier          #+#    #+#             */
/*   Updated: 2018/12/14 19:35:41 by salquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

char	*read_file(const int fd, char *bufcpy)
{
	char	buf[BUFF_SIZE + 1];
	int		size;
	char	*tmp;

	while ((size = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		tmp = bufcpy;
		bufcpy = ft_strjoin(bufcpy, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (bufcpy);
}

int		free_return(char *to_free, int ret_value)
{
	free(to_free);
	return (ret_value);
}

char	*fill_buffer(char *tmp, char *bufcpy)
{
	char *buffer;

	if (!(buffer = ft_strjoin(tmp, bufcpy)))
		return (NULL);
	free(bufcpy);
	free(tmp);
	return (buffer);
}

t_list	*find_create_lst(t_list **tmp_lst, const int fd)
{
	t_list	*lst;
	t_list	*new_lst;

	lst = *tmp_lst;
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
	if (BUFF_SIZE < 1 || fd < 0 || (read(fd, bufcpy, 0) < 0))
		return (-1);
	lst = find_create_lst(&head, fd);
	if ((!lst->content || (lst->content && !ft_strchr(lst->content, '\n'))))
		bufcpy = read_file(fd, bufcpy);
	if (ft_strequ(bufcpy, "") && ft_strequ(lst->content, ""))
		return (free_return(bufcpy, 0));
	if (!(buffer = fill_buffer(lst->content, bufcpy)))
		return (-1);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!(*line = ft_strsub(buffer, 0, i))
		|| !(lst->content = ft_strsub(buffer, i + 1, ft_strlen(buffer) - i)))
		return (-1);
	free(buffer);
	return (1);
}
