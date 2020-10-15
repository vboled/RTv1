/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:33:57 by gweasley          #+#    #+#             */
/*   Updated: 2020/09/16 14:34:02 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		scene_init(t_rtv *scene)
{
	scene->objects = NULL;
	scene->lights = NULL;
	scene->closest = NULL;
	scene->mlx = NULL;
	scene->win = NULL;
	scene->img = NULL;
	scene->pix_m = NULL;
	if (!(scene->closest = (t_closest *)malloc(sizeof(t_closest))))
		return (0);
	scene->camera.tilt_x = 0.0;
	scene->camera.tilt_y = 0.0;
	scene->need_to_redraw = 1;
	return (1);
}

void	memory_free(t_rtv *rtv)
{
	t_obj	*next;
	t_light	*nl;

	while (rtv->objects)
	{
		next = rtv->objects->next;
		free(rtv->objects);
		rtv->objects = next;
	}
	while (rtv->lights)
	{
		nl = rtv->lights->next;
		free(rtv->lights);
		rtv->lights = nl;
	}
	if (rtv->closest)
		free(rtv->closest);
	if (rtv->mlx)
		free(rtv->mlx);
	if (rtv->win)
		free(rtv->win);
	if (rtv->img)
		free(rtv->img);
}

// void	x_close(t_rtv *param)
// {
// 	memory_free(param);
// 	exit(0);
// }

int		main(int argc, char **argv)
{
	t_rtv	scene;

	argc++;
	if (!scene_init(&scene) || !get_data(argv[1], &scene))
	{
		write(1, "ERROR\n", 6);
		memory_free(&scene);
		return (0);
	}
	mlx_hook(scene.win, 2, 5, deal_hook, &scene);
	// mlx_hook(scene.win, 17, 1, x_close, &scene);
	create_mlx_image(&scene);
	mlx_loop(scene.mlx);
	return (0);
}
