/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:43:23 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/17 17:13:20 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *result;

	if (size + 1 == 0)
		return (0);
	if (!(result = (char *)malloc(size + 1)))
		return (0);
	while (1)
	{
		result[size] = '\0';
		if (size == 0)
			return (result);
		size--;
	}
}
