#include "rtv1.h"

int		is_shadow(t_rtv *rtv, double min)
{
	t_obj	*head;
	t_obj	*obj;
	double	closest_t;

	head = rtv->objects;
	closest_t = MAX_T;
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

double	calc_root_for_cone(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj)
{
	double res;

	res = (sq(obj->coeff.c) * sq(d->y * (rtv->camera.pos.x - obj->x) +
		d->x * (-rtv->camera.pos.y + obj->y)) - sq(obj->coeff.b) * sq(d->z *
		(rtv->camera.pos.x - obj->x) + d->x * (-rtv->camera.pos.z + obj->z)) +
		sq(obj->coeff.a) * sq(d->z * (rtv->camera.pos.y - obj->y) + d->y *
		(-rtv->camera.pos.z + obj->z))) / (sq(obj->coeff.a) * sq(obj->coeff.b) *
		sq(obj->coeff.c));
	return (res);
}

void	intersect_cone(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj)
{
	double	root;
	double	der;
	double	el;
	double	mn;

	el = sq(obj->coeff.a) * sq(obj->coeff.c) * d->y * (-rtv->camera.pos.y
		+ obj->y) + sq(obj->coeff.b) * (sq(obj->coeff.c) * d->x *
		(rtv->camera.pos.x - obj->x) + sq(obj->coeff.a) * d->z *
		(rtv->camera.pos.z - obj->z));
	mn = sq(obj->coeff.a) * sq(obj->coeff.b) * sq(obj->coeff.c);
	root = calc_root_for_cone(rtv, o, d, obj);
	der = (sq(obj->coeff.a) * sq(obj->coeff.c) * sq(d->y) - sq(obj->coeff.b)
		* (sq(obj->coeff.c) * sq(d->x) + sq(obj->coeff.a) * sq(d->z)));
	if (root < 0 || der == 0)
	{
		rtv->t1 = MAX_T;
		rtv->t2 = MAX_T;
	}
	else
	{
		root = sqrt(root);
		rtv->t1 = (mn * root + el) / der;
		rtv->t2 = (-mn * root + el) / der;
	}
}
