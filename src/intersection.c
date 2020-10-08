/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:09:54 by gweasley          #+#    #+#             */
/*   Updated: 2020/10/08 16:09:55 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	calculate_t(t_rtv *rtv, double k1, double k2, double k3)
{
	double	disk;

	disk = k2 * k2 - 4 * k1 * k3;
	if (disk < 0)
	{
		rtv->t1 = MAX_T;
		rtv->t2 = MAX_T;
		return ;
	}
	rtv->t1 = (-k2 + sqrt(disk)) / (2.0 * k1);
	rtv->t2 = (-k2 - sqrt(disk)) / (2.0 * k1);
}

void	intersect_sphere(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj)
{
	t_vec	oc;
	double	disk;

	oc.x = o->x - obj->point.x;
	oc.y = o->y - obj->point.y;
	oc.z = o->z - obj->point.z;
	calculate_t(rtv, dot(d, d), 2 * dot(&oc, d),
	dot(&oc, &oc) - sq(obj->scale));
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
	x_dot_n = dot(&x,  &obj->dir);
	rtv->t1 = -x_dot_n / d_dot_n;
	rtv->t2 = rtv->t1;
}

void	intersect_cylinder(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj)
{
	t_vec	x;
	double	a;
	double	b;
	double	c;

	x = vec_dif(o, &obj->point);
	a = dot(d, d) - sq(dot(d, &obj->dir));
	b = 2 * (dot(d, &x) - dot(d, &obj->dir) * dot(&x, &obj->dir));
	c = dot(&x, &x) - sq(dot(&x, &obj->dir)) - sq(obj->scale);
	calculate_t(rtv, a, b, c);
}

void	intersect_obj(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj)
{
	if (obj->type == 1)
		intersect_sphere(rtv, o, d, obj);
	if (obj->type == 2)
		intersect_plane(rtv, o, d, obj);
	if (obj->type == 3)
		intersect_cone(rtv, o, d, obj);
	if (obj->type == 4)
		intersect_cylinder(rtv, o, d, obj);
}

int		closest_intersection(t_rtv *rtv, t_vec *o, t_vec *d, double min)
{
	t_obj	*head;

	rtv->closest->t = MAX_T;
	rtv->closest->obj = 0;
	head = rtv->objects;
	while (head)
	{
		intersect_obj(rtv, o, d, head);
		if (rtv->t1 >= min && rtv->t1 <= MAX_T && rtv->t1 < rtv->closest->t)
		{
			rtv->closest->t = rtv->t1;
			rtv->closest->obj = head;
		}
		if (rtv->t2 >= min && rtv->t2 <= MAX_T && rtv->t2 < rtv->closest->t)
		{
			rtv->closest->t = rtv->t2;
			rtv->closest->obj = head;
		}
		head = head->next;
	}
	if (!rtv->closest->obj)
		return (0);
	return (1);
}
