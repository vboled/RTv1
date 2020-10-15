/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:44:34 by gweasley          #+#    #+#             */
/*   Updated: 2020/10/15 16:12:05 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		counter;
	char		*res;
	size_t		i;

	i = 0;
	counter = 0;
	while (s1[counter] != '\0')
		counter++;
	if (!(res = (char *)malloc(counter + 1)))
		return (0);
	while (i < counter)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
