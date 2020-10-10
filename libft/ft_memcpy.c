/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:30:23 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/16 17:24:05 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		counter;
	void		*result;

	counter = 0;
	result = dst;
	if (dst == 0 && src == 0)
		return (0);
	while (counter < n)
	{
		*((unsigned char *)dst) = *((unsigned char *)src);
		dst++;
		src++;
		counter++;
	}
	return (result);
}
