/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:56:19 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/14 13:04:23 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		counter;
	void		*result;

	result = b;
	counter = 0;
	while (counter < len)
	{
		*((unsigned char *)b) = c;
		b++;
		counter++;
	}
	return (result);
}
