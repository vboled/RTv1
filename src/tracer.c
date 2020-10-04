#include "rtv1.h"

int		change_intensity(int color, double coeff)
{
	int r;
	int g;
	int b;

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

double	specular(t_rtv *rtv, t_light *light, double s)
{
	t_vec	r;
	t_vec	v;
	double	n_dot_l;
	double	r_dot_v;

	if (!s)
		return (0);
	n_dot_l = dot(&(rtv->n), &(rtv->l));
	r.x = 2 * rtv->n.x * n_dot_l - rtv->l.x;
	r.y = 2 * rtv->n.y * n_dot_l - rtv->l.y;
	r.z = 2 * rtv->n.z * n_dot_l - rtv->l.z;
	v.x = -rtv->d.x;
	v.y = -rtv->d.y;
	v.z = -rtv->d.z;
	r_dot_v = dot(&r, &v);
	if (r_dot_v > 0)
		return (light->intens * pow(r_dot_v / vec_len(&r) / vec_len(&v), s));
	return (0.0);
}

double	compute_intens(t_rtv *rtv)
{
	double		intens;
	double		n_dot_l;
	t_light		*head;

	intens = 0.0;
	head = rtv->lights;
	while (head)
	{
		if (head->type == 1)
			intens += head->intens;
		else if (make_l(&(rtv->l), head, &(rtv->p)) && !is_shadow(rtv, 0.0001))
		{
			n_dot_l = dot(&(rtv->n), &(rtv->l));
			if (n_dot_l > 0)
				intens += head->intens * n_dot_l / (vec_len(&(rtv->n))
				* vec_len(&(rtv->l)));
			intens += specular(rtv, head, rtv->closest->obj->specular);
		}
		head = head->next;
	}
	return (intens);
}

int		trace_ray(t_rtv *rtv, t_vec *o, t_vec *d, double min)
{
	double	t;
	int		local_color;
	t_vec	reflected;
	int		reflected_color;

	if (!closest_intersection(rtv, o, d, min))
		return (0xFFFFFF);
	make_p(rtv);
	make_n(rtv);
	return (change_intensity(rtv->closest->obj->color, compute_intens(rtv)));
}

void	tracer(t_rtv *rtv)
{
	int		i;
	int		j;

	j = -WIDTH / 2;
	while (++j < WIDTH / 2)
	{
		i = -HEIGHT / 2;
		while (++i < HEIGHT / 2)
		{
			vec_init(&(rtv->d), j, i);
			vec_rot(rtv, &(rtv->d));
			rtv->pix_m[(i + HEIGHT / 2) * WIDTH + j + WIDTH / 2] =
			trace_ray(rtv, &(rtv->camera.pos), &(rtv->d), 1.0);
		}
	}
}
