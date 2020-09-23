/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:10:54 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/23 13:43:04 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t		counter;

	counter = 0;
	while (src[counter] != '\0')
	{
		dst[counter] = src[counter];
		counter++;
	}
	dst[counter] = '\0';
	return (dst);
}
