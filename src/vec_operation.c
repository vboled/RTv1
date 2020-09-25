#include "rtv1.h"

double	dot(t_vec *lhs, t_vec *rhs)
{
	return (lhs->x * rhs->x + lhs->y * rhs->y + lhs->z * rhs->z);
}

t_vec	makeOC(t_rtv *rtv, t_obj *obj)
{
	t_vec	res;

	res.x = rtv->camera.x - obj->x;
	res.y = rtv->camera.y - obj->y;
	res.z = rtv->camera.x - obj->z;
	return (res);
}

t_vec	makeP(t_rtv *rtv, double t, t_vec *d)
{
	t_vec	res;

	res.x = rtv->camera.x + t * d->x;
	res.y = rtv->camera.y + t * d->y;
	res.z = rtv->camera.z + t * d->z;
	return (res);
}

double	vec_len(t_vec *vec)
{
	return sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

t_vec	makeN(t_vec *p, t_obj* obj)
{
	t_vec	res;
	double	len;

	res.x = p->x - obj->x;
	res.y = p->y - obj->y;
	res.z = p->z - obj->z;
	len = vec_len(&res);
	if (len)
	{
		res.x /= len;
		res.y /= len;
		res.z /= len;
	}
	return (res);
}

void	vecInit(t_vec *d, int x, int y)
{
	d->x = 1.0 * x / WIDTH;
	d->y = -1.0 * y / HEIGHT;
	d->z = 1.0;
}