/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:20:17 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/16 18:10:47 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void			*res;
	size_t			counter;

	res = dst;
	counter = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dst < src)
	{
		while (counter < len)
		{
			((unsigned char *)dst)[counter] = ((unsigned char *)src)[counter];
			counter++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (res);
}
