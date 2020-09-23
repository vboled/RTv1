#include "rtv1.h"

int		deal_hook(int key, t_rtv *param)
{
	if (key == 53)
	{
		write(1, "EXIT\n", 5);
		exit (0);
	}
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
			frac->pix_m[j * WIDTH + i] = 0;
			j++;
		}
		i++;
	}
}

void	create_mlx_image(t_rtv *frac)
{
	frac->pix_m = (int *)mlx_get_data_addr(frac->img,
	&(frac->bits_per_pixel), &(frac->size_line), &(frac->endian));
	// clear_window(frac);
	mlx_clear_window(frac->mlx, frac->win);
	tracer(frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
}
