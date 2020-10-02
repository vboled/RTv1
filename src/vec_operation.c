#include "rtv1.h"

double	dot(t_vec *lhs, t_vec *rhs)
{
	return (lhs->x * rhs->x + lhs->y * rhs->y + lhs->z * rhs->z);
}

void	make_p(t_rtv *rtv)
{
	rtv->p.x = rtv->camera.pos.x + rtv->closest->t * rtv->d.x;
	rtv->p.y = rtv->camera.pos.y + rtv->closest->t * rtv->d.y;
	rtv->p.z = rtv->camera.pos.z + rtv->closest->t * rtv->d.z;
}

double	vec_len(t_vec *vec)
{
	return sqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

void	make_n_for_sphere(t_rtv *rtv)
{
	double	len;

	rtv->n.x = rtv->p.x - rtv->closest->obj->x;
	rtv->n.y = rtv->p.y - rtv->closest->obj->y;
	rtv->n.z = rtv->p.z - rtv->closest->obj->z;
	len = vec_len(&(rtv->n));
	if (len)
	{
		rtv->n.x /= len;
		rtv->n.y /= len;
		rtv->n.z /= len;
	}
}

void	make_n_for_plane(t_rtv *rtv)
{
	double	len;

	rtv->n.x = rtv->closest->obj->coeff.a;
	rtv->n.y = -rtv->closest->obj->coeff.b;
	rtv->n.z = rtv->closest->obj->coeff.c;
	len = vec_len(&(rtv->n));
	if (len)
	{
		rtv->n.x /= len;
		rtv->n.y /= len;
		rtv->n.z /= len;
	}
}

void	make_n(t_rtv *rtv)
{
	
	if (rtv->closest->obj->type == 1)
		make_n_for_sphere(rtv);
	if (rtv->closest->obj->type == 2)
		make_n_for_plane(rtv);
}

void	vecInit(t_vec *d, int x, int y)
{
	d->x = 1.0 * x / WIDTH;
	d->y = -1.0 * y / HEIGHT;
	d->z = 1.0;
}

int		make_l(t_vec *l, t_light *head, t_vec *p)
{
	if (head->type == 2)
	{
		l->x = head->x - p->x;
		l->y = head->y - p->y;
		l->z = head->z - p->z;
	}
	else
	{
		l->x = head->dirX;
		l->y = head->dirY;
		l->z = head->dirZ;
	}
	return (1);
}

t_vec	reverse_vec(t_vec *vec)
{
	t_vec	res;

	res.x = -vec->x;
	res.y = -vec->y;
	res.z = -vec->z;

	return (res);
}