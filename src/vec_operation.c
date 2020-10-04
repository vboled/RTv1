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
	return (sqrtf(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
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

void	vec_rot(t_rtv *rtv, t_vec *d)
{
	double	tmp;

	tmp = d->y * cos(rtv->camera.tilt_x) + d->z * sin(rtv->camera.tilt_x);
	d->z = -d->y * sin(rtv->camera.tilt_x) + d->z * cos(rtv->camera.tilt_x);
	d->y = tmp;
	tmp = d->x * cos(rtv->camera.tilt_y) - d->z * sin(rtv->camera.tilt_y);
	d->z = d->x * sin(rtv->camera.tilt_y) + d->z * cos(rtv->camera.tilt_y);
	d->x = tmp;
}
