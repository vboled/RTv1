/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:31:08 by gweasley          #+#    #+#             */
/*   Updated: 2020/01/02 13:12:39 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4
# include "../libft/libft.h"
# include <fcntl.h>

t_list				*forc_list(t_list **head, const int fd);
int					create(t_list **list, char **line);
int					reading(t_list **list, char **line);
void				cleaning(t_list **head, const int fd, char **line);
int					get_next_line(const int fd, char **line);
#endif
