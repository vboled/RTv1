/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:20:12 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/16 13:52:14 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t		counter;
	size_t		counter1;

	counter1 = 0;
	counter = 0;
	while (s1[counter] != '\0')
		counter++;
	while (s2[counter1] != '\0')
	{
		s1[counter] = s2[counter1];
		counter++;
		counter1++;
	}
	s1[counter] = '\0';
	return (s1);
}
