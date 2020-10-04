#include "rtv1.h"

void	make_n_for_sphere(t_rtv *rtv)
{
	rtv->n.x = rtv->p.x - rtv->closest->obj->x;
	rtv->n.y = rtv->p.y - rtv->closest->obj->y;
	rtv->n.z = rtv->p.z - rtv->closest->obj->z;
}

void	make_n_for_plane(t_rtv *rtv)
{
	rtv->n.x = rtv->closest->obj->coeff.a;
	rtv->n.y = -rtv->closest->obj->coeff.b;
	rtv->n.z = rtv->closest->obj->coeff.c;
}

void	make_n_for_cone(t_rtv *rtv)
{
	rtv->n.x = sq(rtv->closest->obj->coeff.a) /
			(2 * rtv->p.x - rtv->closest->obj->x);
	rtv->n.y = -sq(rtv->closest->obj->coeff.b) /
			(2 * rtv->p.y - rtv->closest->obj->y);
	rtv->n.z = sq(rtv->closest->obj->coeff.c) /
			(2 * rtv->p.z - rtv->closest->obj->z);
}

void	make_n(t_rtv *rtv)
{
	double	len;

	if (rtv->closest->obj->type == 1)
		make_n_for_sphere(rtv);
	if (rtv->closest->obj->type == 2)
		make_n_for_plane(rtv);
	if (rtv->closest->obj->type == 3)
		make_n_for_cone(rtv);
	len = vec_len(&(rtv->n));
	if (len)
	{
		rtv->n.x /= len;
		rtv->n.y /= len;
		rtv->n.z /= len;
	}
}
