/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:30:29 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/16 18:39:48 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((haystack[0] == needle[0] && haystack[0] == '\0') ||
			(len == 0 && needle[0] == '\0') || needle[0] == '\0')
		return ((char *)(haystack));
	if (len == 0 && needle[0] != '\0')
		return (NULL);
	while ((haystack[i] != '\0') && len != 0)
	{
		j = 0;
		while ((haystack[i + j] == needle[j] ||
					needle[j] == '\0') && len - j > 0)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
		len--;
	}
	return (NULL);
}
