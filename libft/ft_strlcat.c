/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:25:31 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/16 13:51:20 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src,
		size_t size)
{
	size_t	i;
	size_t	k;
	size_t	j;

	k = 0;
	i = ft_strlen(dst);
	j = i;
	while ((int)(size - i - 1) > 0 && src[k] != '\0' && k < size - 1)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	k = ft_strlen(src);
	if (j + k < k + size)
		return (j + k);
	return (k + size);
}
