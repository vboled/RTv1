/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:09:42 by gweasley          #+#    #+#             */
/*   Updated: 2020/10/08 16:09:43 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	clear_window(t_rtv *frac)
{
	int		i;
	int		j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < 10)
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
	tracer(frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 85);
}
