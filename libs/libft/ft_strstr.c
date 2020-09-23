/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:52:54 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/16 14:40:11 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *tmp;
	char *tmp1;

	if (*needle == 0 && *haystack == 0)
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		tmp = (char *)needle;
		tmp1 = (char *)haystack;
		while (*needle == *haystack && *needle != '\0' && *haystack != '\0')
		{
			needle++;
			haystack++;
		}
		if (*needle == '\0')
			return (tmp1);
		needle = tmp;
		haystack = tmp1 + 1;
	}
	return (0);
}
