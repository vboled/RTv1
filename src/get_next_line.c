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

#include "rtv1.h"

static char		*process_buffer(char **buffer, char *endl)
{
	char	*str;
	char	*tmp;

	str = (endl == NULL ? *buffer : ft_strndup(*buffer, endl - *buffer));
	if (endl != NULL && str == NULL)
	{
		return (NULL);
	}
	tmp = (endl == NULL ? NULL : *buffer);
	*buffer = (endl == NULL ? NULL : ft_strdup(endl + 1));
	if (endl != NULL && *buffer == NULL)
	{
		return (NULL);
	}
	ft_strdel(&tmp);
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char		*buffers[FD_MAX];
	char			buf[BUF_SIZE + 1];
	ssize_t			ret;
	char			*endl;
	char			*tmp;

	if (buffers[fd] == NULL)
		buffers[fd] = ft_strnew(0);
	if (buffers[fd] == NULL)
		return (-1);
	endl = ft_strchr(buffers[fd], '\n');
	while (endl == NULL && (ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = buffers[fd];
		if (!(buffers[fd] = ft_strjoin(tmp, buf)))
			return (-1);
		ft_strdel(&tmp);
		if (ft_strchr(buf, '\n') && (endl = ft_strchr(buffers[fd], '\n')))
			break ;
	}
	*line = (*buffers[fd] != '\0' ? process_buffer(&buffers[fd], endl) : NULL);
	if (*line == NULL)
		ft_strdel(&buffers[fd]);
	return (*line == NULL ? (int)ret : 1);
}