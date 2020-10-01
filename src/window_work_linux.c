#include "rtv1.h"

void	rotation(t_rtv *rtv, int key)
{
	rtv->need_to_redraw = 1;
	if (key == 65362 || key == 126)
		rtv->camera.tilt_x += 0.05;
	if (key == 65364 || key == 125)
		rtv->camera.tilt_x -= 0.05;
	if (key == 65363 || key == 124)
		rtv->camera.tilt_y -= 0.05;
	if (key == 65361 || key == 123)
		rtv->camera.tilt_y += 0.05;
}

void	moving(t_rtv *rtv, int key)
{
	rtv->need_to_redraw = 1;
	if (key == 119)
		rtv->camera.pos.z += 0.05;
	if (key == 115)
		rtv->camera.pos.z -= 0.05;
	if (key == 97)
		rtv->camera.pos.x -= 0.05;
	if (key == 100)
		rtv->camera.pos.x += 0.05;
	if (key == 32)
		rtv->camera.pos.y += 0.05;
	if (key == 65507)
		rtv->camera.pos.y -= 0.05;
}

int		deal_hook(int key, t_rtv *param)
{
	if ((key >= 65361 && key <= 65364) || (key >= 123 && key <= 126))
		rotation(param, key);
	if (key == 119 || key == 115 || key == 97 || key == 100 ||
		key == 32 || key == 65507)
		moving(param, key);
	if (key == 53 || key == 65307)
	{
		write(1, "EXIT\n", 5);
		exit (0);
	}
	if (param->need_to_redraw)
		create_mlx_image(param);
	param->need_to_redraw = 0;
	return (0);
}

