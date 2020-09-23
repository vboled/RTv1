/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:43:54 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/16 13:50:25 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*copy;
	char	*tmp;

	copy = (char *)s;
	tmp = 0;
	while (*copy != '\0')
	{
		if (*copy == (char)c)
			tmp = copy;
		copy++;
	}
	if ((char)c == '\0')
		return (copy);
	if (tmp)
		return (tmp);
	return (0);
}
