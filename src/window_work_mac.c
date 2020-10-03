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
	rtv->need_to_redraw = 1;
	if (key == 13)
		rtv->camera.pos.z += 0.3;
	if (key == 1)
		rtv->camera.pos.z -= 0.3;
	if (key == 0)
		rtv->camera.pos.x -= 0.3;
	if (key == 2)
		rtv->camera.pos.x += 0.3;
	if (key == 49)
		rtv->camera.pos.y += 0.3;
	if (key == 256)
		rtv->camera.pos.y -= 0.3;
}

int		deal_hook(int key, t_rtv *param)
{
	if (key >= 123 && key <= 126)
		rotation(param, key);
	if (key == 13 || key == 1 || key == 0 || key == 2 ||
		key == 49 || key == 256)
		moving(param, key);
	if (key == 53)
	{
		write(1, "EXIT\n", 5);
		exit (0);
	}
	if (param->need_to_redraw)
		create_mlx_image(param);
	param->need_to_redraw = 0;
	return (0);
}

