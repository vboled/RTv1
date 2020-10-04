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
	if (!(scene->depth = (int *)malloc(sizeof(int))))
		return (0);
	if (!(scene->closest = (t_closest *)malloc(sizeof(t_closest))))
		return (0);
	scene->camera.tilt_x = 0.0;
	scene->camera.tilt_y = 0.0;
	scene->need_to_redraw = 1;
	return (1);
}

int		main(int argc, char **argv)
{
	t_rtv	scene;

	if (!scene_init(&scene) || !get_data(argv[1], &scene))
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	mlx_hook(scene.win, 2, 5, deal_hook, &scene);
	create_mlx_image(&scene);
	mlx_loop(scene.mlx);
	return (0);
}
