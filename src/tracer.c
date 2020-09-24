#include "rtv1.h"

double	dot(t_vec *lhs, t_vec *rhs)
{
	return (lhs->x * rhs->x + lhs->y * rhs->y + lhs->z * rhs->z);
}

double	intersectSpehere(t_rtv *rtv, t_vec *d, t_vec oc, double rad)
{
	double	k1;
	double	k2;
	double	k3;
	double	disk;

	k1 = dot(d, d);
	k2 = 2.0 * dot(&oc, d);
	k3 = dot(&oc, &oc) - rad * rad;
	disk = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
		return (INT_MAX);
	int x = (-k2 + sqrt(disk)) / (2.0 * k1);
	int y = (-k2 - sqrt(disk)) / (2.0 * k1);
	if (x < y)
		return (x);
	return (y);
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
	res.x = rtv->camera.y + t * d->y;
	res.x = rtv->camera.z + t * d->z;
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

double	computeIntens(t_rtv *rtv, t_vec p, t_vec n)
{
	double		intens, n_dot_l;
	t_light		*head;
	t_vec		l;

	intens = 0.0;
	head = rtv->lights;
	while (head)
	{
		if (head->type == 1)
			intens += head->intens;
		else if (head->type == 2)
		{
			l.x = head->x - p.x;
			l.y = head->y - p.y;
			l.z = head->z - p.z;
		}
		else
		{
			l.x = head->dirX;
			l.y = head->dirY;
			l.z = head->dirZ;
		}
		n_dot_l = dot(&n, &p);
		if (n_dot_l > 0)
			intens += head->intens * n_dot_l / vec_len(&n) / vec_len(&l);
		head = head->next;
	}
	return (intens);
}

int		change_intensity(int color, double coeff)
{
	int r;
	int g;
	int b;

	// if (!coeff)
		// return (color);
	r = ((color >> 16) & 0xFF) * coeff;
	g = ((color >> 8) & 0xFF) * coeff;
	b = (color & 0xFF) * coeff;
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	return ((r & 0xff) << 16 | (g & 0xff) << 8 | (b & 0xff));
}

int		traceRay(t_rtv *rtv, t_vec *d)
{
	double	t, closest_t;
	t_obj	*head;
	t_obj	*closest_obj;
	t_vec	p;

	closest_obj = 0;
	closest_t = INT_MAX;
	head = rtv->objects;
	while (head)
	{
		t = intersectSpehere(rtv, d, makeOC(rtv, head), head->scale);
		if (t >= 1 && t <= INT_MAX && t < closest_t)
		{
			closest_t = t;
			closest_obj = head;
		}
		head = head->next;
	}
	if (!closest_obj)
		return (0xFFFFFF);
	p = makeP(rtv, closest_t, d);
	// return closest_obj->color;
	return (change_intensity(closest_obj->color, computeIntens(rtv, p, makeN(&p, closest_obj))));
}

void	vecInit(t_vec *d, int x, int y)
{
	d->x = 1.0 * x / WIDTH;
	d->y = -1.0 * y / HEIGHT;
	d->z = 1.0;
}

void	tracer(t_rtv *rtv)
{
	int		i;
	int		j;
	t_vec	D;

	// double k = 0.0;
	// t_obj *head = rtv->objects;
	// while (head)
	// {
	// 	head->color = change_intensity(0xFF0000, k);
	// 	head = head->next;
	// 	k += 0.25;
	// }
	j = -WIDTH / 2;
	while (++j < WIDTH / 2)
	{
		i = -HEIGHT / 2;
		while (++i < HEIGHT / 2)
		{
			vecInit(&D, j, i);
			int color = traceRay(rtv, &D);
			rtv->pix_m[(i + HEIGHT / 2) * WIDTH + j + WIDTH / 2] = color;
			// if (color)
				// printf("%d, ", color);
		}
	}
}