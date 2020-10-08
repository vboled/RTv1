/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:09:59 by gweasley          #+#    #+#             */
/*   Updated: 2020/10/08 16:10:00 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		is_shadow(t_rtv *rtv, double min, double max, t_light *light)
{
	t_obj	*head;
	t_obj	*obj;
	double	closest_t;

	head = rtv->objects;
	closest_t = max;
	obj = 0;
	while (head)
	{
		intersect_obj(rtv, &(rtv->p), &(rtv->l), head);
		if (rtv->t1 > min && rtv->t1 < MAX_T && rtv->t1 < closest_t)
		{
			closest_t = rtv->t1;
			obj = head;
		}
		if (rtv->t2 > min && rtv->t2 < MAX_T && rtv->t2 < closest_t)
		{
			closest_t = rtv->t2;
			obj = head;
		}
		head = head->next;
	}
	if (obj)
		return (1);
	return (0);
}

void	intersect_cone(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj)
{
	t_vec	x;
	double	a;
	double	b;
	double	c;

	x = vec_dif(o, &obj->point);
	a = dot(d, d) - (1 + sq(obj->angle)) * sq(dot(d, &obj->dir));
	b = dot(d, &x) - (1 + sq(obj->angle)) * dot(d, &obj->dir) *
		dot(&x, &obj->dir);
	c = dot(&x, &x) - (1 + sq(obj->angle)) * sq(dot(&x, &obj->dir));
	calculate_t(rtv, a, 2 * b, c);
}

void	intersect_plane(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj)
{
	t_vec	x;
	double	x_dot_n;
	double	d_dot_n;

	x = vec_dif(o, &obj->point);
	vec_norm(&obj->dir);
	d_dot_n = dot(d, &obj->dir);
	if (d_dot_n == 0)
	{
		rtv->t1 = MAX_T;
		rtv->t2 = MAX_T;
		return ;
	}
	x_dot_n = dot(&x, &obj->dir);
	rtv->t1 = -x_dot_n / d_dot_n;
	rtv->t2 = rtv->t1;
}

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
