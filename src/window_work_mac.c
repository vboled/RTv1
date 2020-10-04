#include "rtv1.h"

void	rotation(t_rtv *rtv, int key)
{
	rtv->need_to_redraw = 1;
	if (key == 126)
		rtv->camera.tilt_x += 0.3;
	if (key == 125)
		rtv->camera.tilt_x -= 0.3;
	if (key == 124)
		rtv->camera.tilt_y -= 0.3;
	if (key == 123)
		rtv->camera.tilt_y += 0.3;
}

void	moving(t_rtv *rtv, int key)
{
	t_vec	d;
	double	len;

	rtv->need_to_redraw = 1;
	vec_init(&d, 0, 0);
	vec_rot(rtv, &d);
	len = vec_len(&d);
	if (len != 0)
	{
		d.x /= len;
		d.y /= len;
		d.z /= len;
		if (key == 1)
		{
			rtv->camera.pos.x -= d.x;
			rtv->camera.pos.y -= d.y;
			rtv->camera.pos.z -= d.z;
		}
		if (key == 13)
		{
			rtv->camera.pos.x += d.x;
			rtv->camera.pos.y += d.y;
			rtv->camera.pos.z += d.z;
		}
	}
}

int		deal_hook(int key, t_rtv *param)
{
	if (key >= 123 && key <= 126)
		rotation(param, key);
	if (key == 13 || key == 1)
		moving(param, key);
	if (key == 53)
	{
		write(1, "EXIT\n", 5);
		exit(0);
	}
	if (param->need_to_redraw)
		create_mlx_image(param);
	param->need_to_redraw = 0;
	return (0);
}
