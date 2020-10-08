/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_work_linux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:10:48 by gweasley          #+#    #+#             */
/*   Updated: 2020/10/08 16:10:49 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotation(t_rtv *rtv, int key)
{
	rtv->need_to_redraw = 1;
	if (key == 65362)
		rtv->camera.tilt_x += 0.3;
	if (key == 65364)
		rtv->camera.tilt_x -= 0.3;
	if (key == 65363)
		rtv->camera.tilt_y -= 0.3;
	if (key == 65361)
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
		if (key == 115)
		{
			rtv->camera.pos.x -= d.x;
			rtv->camera.pos.y -= d.y;
			rtv->camera.pos.z -= d.z;
		}
		if (key == 119)
		{
			rtv->camera.pos.x += d.x;
			rtv->camera.pos.y += d.y;
			rtv->camera.pos.z += d.z;
		}
	}
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
		memory_free(param);
		write(1, "EXIT\n", 5);
		exit(0);
	}
	if (param->need_to_redraw)
		create_mlx_image(param);
	param->need_to_redraw = 0;
	return (0);
}
