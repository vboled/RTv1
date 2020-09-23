#include "rtv1.h"

double	dot(t_vec *lhs, t_vec *rhs)
{
	return (lhs->x * rhs->x + lhs->y * rhs->y + lhs->z * rhs->z);
}

double	intersectSpehere(t_rtv *rtv, t_vec *D, t_vec OC, double rad)
{
	double k1, k2, k3, disk;

	k1 = dot(D, D);
	k2 = 2.0 * dot(&OC, D);
	k3 = dot(&OC, &OC) - rad * rad;
	disk = k2 * k2 - 4 * k1 * k3;
	if (D < 0)
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

int		traceRay(t_rtv *rtv, t_vec *D)
{
	double	t, closest_t;
	t_obj	*head;
	t_obj	*closest_obj;

	closest_obj = 0;
	closest_t = INT_MAX;
	head = rtv->objects;
	while (head)
	{
		t = intersectSpehere(rtv, D, makeOC(rtv, head), head->scale);
		if (t >= 1 && t <= INT_MAX && t < closest_t)
		{
			closest_t = t;
			closest_obj = head;
		}
		head = head->next;
	}
	if (!closest_obj)
		return (0xFFFFFF);
	return (closest_obj->color);
}

void	vecInit(t_vec *D, int x, int y)
{
	D->x = 1.0 * x / WIDTH;
	D->y = -1.0 * y / HEIGHT;
	D->z = 1.0;
}

void	tracer(t_rtv *rtv)
{
	int		i;
	int		j;
	t_vec	D;

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