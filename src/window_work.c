#include "rtv1.h"

void	rotation(t_rtv *rtv, int key)
{
	if (key == 65362 || key == 126)
		rtv->rot_x += 0.05;
	if (key == 65364 || key == 125)
		rtv->rot_x -= 0.05;
	if (key == 65363 || key == 124)
		rtv->rot_y -= 0.05;
	if (key == 65361 || key == 123)
		rtv->rot_y += 0.05;
}

int		deal_hook(int key, t_rtv *param)
{
	if ((key >= 65361 && key <= 65364) || (key >= 123 && key <= 126))
		rotation(param, key);
	if (key == 53 || key == 65307)
	{
		write(1, "EXIT\n", 5);
		exit (0);
	}
	create_mlx_image(param);
	return (0);
}

void	clear_window(t_rtv *frac)
{
	int		i;
	int		j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			frac->pix_m[i * WIDTH + j] = 0;
			j++;
		}
		i++;
	}
}

void	create_mlx_image(t_rtv *frac)
{
	frac->pix_m = (int *)mlx_get_data_addr(frac->img,
	&(frac->bits_per_pixel), &(frac->size_line), &(frac->endian));
	clear_window(frac);
	mlx_clear_window(frac->mlx, frac->win);
	tracer(frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
}
