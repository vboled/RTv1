#include "rtv1.h"

void	intersectSpehere(t_rtv *rtv, double *t1, double *t2, int x, int y, t_obj *obj)
{
	double k1, k2, k3, D;

	k1 = 1.0 * x * x / WIDTH / WIDTH + y * 1.0 * y * y / HEIGHT / HEIGHT + 1;
	k2 = 2 * (1.0 * (obj->x - rtv->camera.x) * x / WIDTH + 1.0 * (obj->y - rtv->camera.y) * y / HEIGHT + 1.0 * (obj->z - rtv->camera.z));
	k3 = (obj->x - rtv->camera.x) * (obj->x - rtv->camera.x) + (obj->y - rtv->camera.y) * (obj->y - rtv->camera.y) +
			(obj->z - rtv->camera.z) * (obj->z - rtv->camera.z) - obj->scale * obj->scale;
	D = k2 * k2 - 4 * k1 * k3;
	if (D < 0)
	{
		*t1 = INT_MAX;
		*t2 = INT_MAX;
		return ;
	}
	*t1 = (-k2 + sqrt(D)) / (2.0 * k1);
	*t1 = (-k2 - sqrt(D)) / (2.0 * k1);
	if (*t1 >= 1 && *t1 < INT_MAX)
		printf("t1 = %f\n", *t1);
	if (*t2 >= 1 && *t2 < INT_MAX)
		printf("t2 = %f\n", *t2);
}

int		traceRay(t_rtv *rtv, int x, int y)
{
	double	t1, t2, closest_t;
	t_obj	*head;
	t_obj	*closest_obj;

	closest_obj = 0;
	closest_t = INT_MAX;
	head = rtv->objects;
	while (head)
	{
		intersectSpehere(rtv, &t1, &t2, x, y, head);
		if (t1 >= 1 && t1 <= INT_MAX && t1 < closest_t)
		{
			closest_t = t1;
			closest_obj = head;
		}
		if (t2 >= 1 && t2 <= INT_MAX && t2 < closest_t)
		{
			closest_t = t2;
			closest_obj = head;
		}
		// if (closest_t != INT_MAX)
			// printf("%f\n", closest_t);
		head = head->next;
	}
	if (!closest_obj)
		return (0xFFFFFF);
	return (closest_obj->color);
}

void	tracer(t_rtv *rtv)
{
	int i;
	int j;

	j = -1;
	while (++j < WIDTH)
	{
		i = -1;
		while (++i < HEIGHT)
		{
			int color = traceRay(rtv, j, i);
			rtv->pix_m[i * WIDTH + j] = color;
			// if (color)
				// printf("%d, ", color);
		}
	}
}