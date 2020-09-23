/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:57:34 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/20 18:59:33 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	counter;

	if (!s || !f)
		return ;
	counter = 0;
	while (s[counter])
	{
		(*f)(counter, &(s[counter]));
		counter++;
	}
}
