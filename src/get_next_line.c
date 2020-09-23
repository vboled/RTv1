/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:54:01 by gweasley          #+#    #+#             */
/*   Updated: 2020/09/06 16:38:31 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*forc_list(t_list **head, const int fd)
{
	t_list	*list;

	list = *head;
	if (!list)
	{
		if ((list = ft_lstnew("\0", 1)) == NULL)
			return (NULL);
		list->content_size = fd;
		*head = list;
		return (list);
	}
	while (list)
	{
		if (list->content_size == (size_t)fd)
			return (list);
		if (!(list->next))
			break ;
		list = list->next;
	}
	if ((list->next = ft_lstnew("\0", 1)) == NULL)
		return (NULL);
	list->next->content_size = fd;
	return (list->next);
}

int		create(t_list **list, char **line)
{
	char	*tmp;
	int		len;

	if (ft_strchr((*list)->content, '\n'))
		tmp = ft_strchr((*list)->content, '\n');
	else
		tmp = ft_strchr((*list)->content, '\0');
	len = (tmp - (char *)(*list)->content);
	if (!(*line = (char *)malloc(sizeof(char) * len + 1)))
		return (-1);
	*line = ft_strncpy(*line, (*list)->content, len);
	*(*line + len) = '\0';
	len = ft_strlen((*list)->content) - len;
	if (len != 0)
		(*list)->content = ft_memmove((*list)->content, tmp + 1, len);
	else
		(*list)->content = ft_memmove((*list)->content, tmp, 1);
	return (1);
}

int		reading(t_list **list, char **line)
{
	int		num_read;
	char	str[BUFF_SIZE + 1];
	char	*tmp;

	while (!ft_strchr((*list)->content, '\n'))
	{
		num_read = read((*list)->content_size, str, BUFF_SIZE);
		str[num_read] = '\0';
		if (num_read == -1)
			return (-1);
		if (num_read == 0)
			break ;
		if (!(tmp = ft_strjoin((*list)->content, str)))
			return (-1);
		free((*list)->content);
		(*list)->content = tmp;
	}
	if (*((char *)(*list)->content) == '\0')
		return (0);
	return (create(list, line));
}

void	cleaning(t_list **head, const int fd, char **line)
{
	t_list	*list;
	t_list	*tmp;

	*line = (char *)malloc(sizeof(char));
	**line = '\0';
	tmp = *head;
	list = NULL;
	if (tmp->content_size == (size_t)fd)
	{
		free((*head)->content);
		*head = tmp->next;
		free(tmp);
		return ;
	}
	while (!(tmp->content_size == (size_t)fd))
	{
		list = tmp;
		tmp = tmp->next;
	}
	list->next = tmp->next;
	free(tmp->content);
	free(tmp);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	static t_list	*head;
	t_list			*list;

	if (fd < 0 || !line || !(list = forc_list(&head, fd)))
		return (-1);
	i = reading(&list, line);
	if (i == -1 || i == 0)
		cleaning(&head, fd, line);
	return (i);
}
