/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:32:51 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/20 18:13:58 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char			tmp;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n == -2147483648)
		ft_putstr("2147483648");
	else if (n > 9)
	{
		tmp = n % 10 + '0';
		ft_putnbr(n / 10);
		ft_putchar(tmp);
	}
	else
	{
		tmp = n + '0';
		ft_putchar(tmp);
	}
}
