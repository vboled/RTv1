#include "rtv1.h"

int		is_shadow(t_rtv *rtv, double min)
{
	return (0);
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
