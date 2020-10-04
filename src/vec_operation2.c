#include "rtv1.h"

double	sq(double num)
{
	return (num * num);
}

t_vec	reverse_vec(t_vec *vec)
{
	t_vec	res;

	res.x = -vec->x;
	res.y = -vec->y;
	res.z = -vec->z;
	return (res);
}

void	vec_init(t_vec *d, int x, int y)
{
	d->x = 1.0 * x / WIDTH;
	d->y = -1.0 * y / HEIGHT;
	d->z = 1.0;
}
