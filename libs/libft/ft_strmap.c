/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:19:20 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/20 18:54:51 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*res;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s || !(res = (char *)malloc(ft_strlen(s) + 1)))
		return (0);
	while (s[i])
	{
		if ((*f)(s[i]))
		{
			res[j] = (*f)(s[i]);
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}
