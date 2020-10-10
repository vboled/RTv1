/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:47:08 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/16 18:32:07 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		counter;

	counter = 0;
	while (counter < n)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		dst++;
		if (*((unsigned char *)src) == (unsigned char)c)
			return (dst);
		counter++;
		src++;
	}
	if (counter == n)
		return (0);
	return (dst);
}
