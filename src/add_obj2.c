#include "rtv1.h"

int		read_points(char **param, t_vec *p1, t_vec *p2, t_vec *p3)
{
	if (!param[12])
		return (0);
	p1->x = ft_atoi(param[1]);
	p1->y = ft_atoi(param[2]);
	p1->z = ft_atoi(param[3]);
	p2->x = ft_atoi(param[4]);
	p2->y = ft_atoi(param[5]);
	p2->z = ft_atoi(param[6]);
	p3->x = ft_atoi(param[7]);
	p3->y = ft_atoi(param[8]);
	p3->z = ft_atoi(param[9]);
	return (1);
}

void	calculate_coef(t_obj *obj, t_vec *p1, t_vec *p2, t_vec *p3)
{
	obj->coeff.a = -p1->z * p2->y + p1->y * p2->z +
					p1->z * p3->y - p2->z * p3->y -
					p1->y * p3->z + p2->y * p3->z;
	obj->coeff.b = p1->z * p2->x - p1->x * p2->z -
					p1->z * p3->x + p2->z * p3->x +
					p1->x * p3->z - p2->x * p3->z;
	obj->coeff.c = -p1->y * p2->x + p1->x * p2->y +
					p1->y * p3->x - p2->y * p3->x -
					p1->x * p3->y + p2->x * p3->y;
	obj->coeff.d = p1->z * p2->y * p3->x - p1->y *
					p2->z * p3->x - p1->z * p2->x *
					p3->y + p1->x * p2->z * p3->y +
					p1->y * p2->x * p3->z - p1->x * p2->y * p3->z;
}

int		get_plane_param(t_obj *obj, char **param)
{
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;

	if (!read_points(param, &p1, &p2, &p3))
		return (0);
	obj->type = 2;
	calculate_coef(obj, &p1, &p2, &p3);
	obj->color = ft_atoi(param[10]);
	obj->specular = ft_atoi(param[11]);
	obj->reflective = ft_atoi(param[12]) / 100.0;
	if (obj->reflective > 1.0)
		obj->reflective = 1.0;
	if (obj->reflective < 0)
		obj->reflective = 0.0;
	return (1);
}
