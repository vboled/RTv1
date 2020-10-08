#include "rtv1.h"

void	make_n_for_sphere(t_rtv *rtv)
{
	rtv->n.x = rtv->p.x - rtv->closest->obj->point.x;
	rtv->n.y = rtv->p.y - rtv->closest->obj->point.y;
	rtv->n.z = rtv->p.z - rtv->closest->obj->point.z;
	vec_norm(&rtv->n);
}

void	make_n_for_plane(t_rtv *rtv)
{
	// vec_copy(&rtv->n, &rtv->closest->obj->dir);
}

void	make_n_for_cone(t_rtv *rtv)
{
	double	m;
	t_vec	x;
	t_vec	v_m;

	x = vec_dif(&rtv->camera.pos, &rtv->closest->obj->point);
	m = dot(&rtv->d, &rtv->closest->obj->dir) * rtv->closest->t +
		dot(&x, &rtv->closest->obj->dir);
	v_m = vec_mult_num(&rtv->closest->obj->dir, m);
	rtv->n = vec_dif(&rtv->p, &rtv->closest->obj->point);
	rtv->n = vec_dif(&rtv->n, &v_m);
	v_m = vec_mult_num(&v_m, (1 + sq(rtv->closest->obj->angle)));
	rtv->n = vec_dif(&rtv->n, &v_m);
	vec_norm(&rtv->n);
}

void	make_n_for_cylinder(t_rtv *rtv)
{
	double m;
	t_vec  x;
	t_vec  v_m;

	x = vec_dif(&rtv->camera.pos, &rtv->closest->obj->point);
	m = dot(&rtv->d, &rtv->closest->obj->dir) * rtv->closest->t +
	dot(&x, &rtv->closest->obj->dir);
	v_m = vec_mult_num(&rtv->closest->obj->dir, m);	
	rtv->n = vec_dif(&rtv->p, &rtv->closest->obj->point);
	rtv->n = vec_dif(&rtv->n, &v_m);
	vec_norm(&rtv->n);
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
	if (rtv->closest->obj->type == 4)
		make_n_for_cylinder(rtv);
}
