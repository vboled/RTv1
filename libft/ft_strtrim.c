/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:52:15 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/21 17:12:07 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_space(char s)
{
	if (s == ' ' || s == '\t' || s == '\n')
		return (1);
	return (0);
}

static size_t		find_first(char const *s)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (!is_space(s[i]))
			return (i);
		i++;
	}
	return (0);
}

static size_t		find_last(char const *s)
{
	size_t		i;

	i = ft_strlen(s);
	while (i != 0)
	{
		if (!is_space(s[i - 1]))
			return (i);
		i--;
	}
	return (i);
}

char				*ft_strtrim(char const *s)
{
	char		*res;
	size_t		i;
	size_t		last;
	size_t		first;

	i = 0;
	if (!s)
		return (0);
	first = find_first(s);
	last = find_last(s);
	if (!(res = (char *)malloc(last - first + 1)))
		return (0);
	i = 0;
	while (i < (last - first))
	{
		res[i] = s[first + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
