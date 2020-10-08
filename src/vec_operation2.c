/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:10:36 by gweasley          #+#    #+#             */
/*   Updated: 2020/10/08 16:10:37 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	sq(double num)
{
	return (num * num);
}

t_vec	reverse_vec(t_vec *vec)
{
	t_vec	res;

	res.x = -vec->x;
	res.y = -vec->y;
	res.z = -vec->z;
	return (res);
}

void	vec_init(t_vec *d, int x, int y)
{
	d->x = 1.0 * x / WIDTH;
	d->y = -1.0 * y / HEIGHT;
	d->z = 1.0;
}

t_vec	vec_dif(const t_vec *lhs, const t_vec *rhs)
{
	t_vec	res;

	res.x = lhs->x - rhs->x;
	res.y = lhs->y - rhs->y;
	res.z = lhs->z - rhs->z;
	return (res);
}

void	vec_copy(const t_vec *source, t_vec *dist)
{
	dist->x = source->x;
	dist->y = source->y;
	dist->z = source->z;
}

void	vec_norm(t_vec *vec)
{
	double len;

	len = vec_len(vec);
	if (len != 0)
	{
		vec->x /= len;
		vec->y /= len;
		vec->z /= len;
	}
}

t_vec	vec_mult_num(const t_vec *vec, double num)
{
	t_vec res;

	res.x = vec->x * num;
	res.y = vec->y * num;
	res.z = vec->z * num;
	return (res);
}
