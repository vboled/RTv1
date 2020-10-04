#include "rtv1.h"

void	t_for_sphere(t_rtv *rtv, t_vec *oc, t_vec *d, double rad)
{
	double		k1;
	double		k2;
	double		k3;
	double		disk;

	k1 = dot(d, d);
	k2 = 2 * dot(oc, d);
	k3 = dot(oc, oc) - rad * rad;
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

	oc.x = o->x - obj->x;
	oc.y = o->y - obj->y;
	oc.z = o->z - obj->z;
	t_for_sphere(rtv, &oc, d, obj->scale);
}

void	intersect_plane(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj)
{
	rtv->t1 = (-obj->coeff.d - obj->coeff.a * o->x - obj->coeff.b *
	o->y - obj->coeff.c * o->z) / (-obj->coeff.a * d->x + obj->coeff.b
	* d->y + obj->coeff.c * d->z);
	rtv->t2 = rtv->t1;
}

void	intersect_obj(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj)
{
	if (obj->type == 1)
		intersect_sphere(rtv, o, d, obj);
	if (obj->type == 2)
		intersect_plane(rtv, o, d, obj);
	if (obj->type == 3)
		intersect_cone(rtv, o, d, obj);
}

int		closest_intersection(t_rtv *rtv, t_vec *o, t_vec *d, double min)
{
	t_obj	*head;
	double	min_t;

	rtv->closest->t = MAX_T;
	rtv->closest->obj = 0;
	head = rtv->objects;
	while (head)
	{
		intersect_obj(rtv, o, d, head);
		if (rtv->t1 >= min_t && rtv->t1 <= MAX_T && rtv->t1 < rtv->closest->t)
		{
			rtv->closest->t = rtv->t1;
			rtv->closest->obj = head;
		}
		if (rtv->t2 >= min_t && rtv->t2 <= MAX_T && rtv->t2 < rtv->closest->t)
		{
			rtv->closest->t = rtv->t2;
			rtv->closest->obj = head;
		}
		head = head->next;
	}
	if (rtv->closest->obj)
		return (1);
	return (0);
}
