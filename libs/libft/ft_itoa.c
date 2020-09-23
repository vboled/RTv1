/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:54:54 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/20 17:22:13 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		num_razr(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*res;
	int				i;
	unsigned int	tmp;

	i = num_razr(n);
	if (!(res = (char *)malloc(i + 1)))
		return (0);
	res[i] = '\0';
	tmp = n;
	if (n < 0)
	{
		res[0] = '-';
		tmp = n * (-1);
	}
	while (1)
	{
		i--;
		res[i] = tmp % 10 + '0';
		tmp /= 10;
		if (tmp == 0)
			return (res);
	}
	return (res);
}
