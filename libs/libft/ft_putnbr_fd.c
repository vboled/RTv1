/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:28:23 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/20 18:33:36 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			tmp;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n == -2147483648)
		ft_putstr_fd("2147483648", fd);
	else if (n > 9)
	{
		tmp = n % 10 + '0';
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(tmp, fd);
	}
	else
	{
		tmp = n + '0';
		ft_putchar_fd(tmp, fd);
	}
}
