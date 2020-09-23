/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:14:55 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/16 18:37:22 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		counter;

	counter = 0;
	while (counter < len)
	{
		if (src[counter] != '\0')
			dst[counter] = src[counter];
		else
			while (counter < len)
			{
				dst[counter] = '\0';
				counter++;
			}
		counter++;
	}
	return (dst);
}
