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
#include <stdio.h>

void	printScene(t_rtv *scene)
{
	printf("camera:\npos_x = %f, pos_y = %f, pos_z = %f\n", scene->camera.x, scene->camera.y, scene->camera.z);
	printf("tilt_x = %f, tilt_y = %f, tilt_z = %f\n", scene->camera.tilt_x, scene->camera.tilt_y, scene->camera.tilt_z);
	t_obj *head;
	head = scene->objects;
	// while (head)
	// {
	// 	if (head->type == 1)
	// 		printf("sphere:");
	// 	printf("\npos_x = %f, pos_y = %f, pos_z = %f\n", head->x, head->y, head->z);
	// 	printf("scale = %f, tilt_x = %f, tilt_y = %f, tilt_z = %f\n", head->scale, head->tilt_x, head->tilt_y, head->tilt_z);
	// 	printf("color = %d\n", head->color);
	// 	head = head->next;
	// }
	printf("LIGHTS:\n");
	t_light *headl;
	headl = scene->lights;
	while (headl)
	{
		printf("type: %f\n", headl->intens);
		headl = headl->next;
	}
}

void	scene_init(t_rtv *scene)
{
	scene->camera.x = 0;
	scene->camera.y = 1;
	scene->camera.z = -1;
	scene->camera.tilt_x = 0.0;
	scene->camera.tilt_y = 0.0;
	scene->camera.tilt_z = 1.0;
	scene->objects = NULL;
}

int		main(int argc, char **argv){
	t_rtv	scene;

	scene_init(&scene);
	if (!getData(argv[1], &scene))
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	// printScene(&scene);
	// mlx_hook(scene.win, 6, 1 << 8, mouse_motion, frac);
	mlx_hook(scene.win, 2, 5, deal_hook, &scene);
	// mlx_hook(scene.win, 4, 3, mouse_hook, frac);
	create_mlx_image(&scene);
	mlx_loop(scene.mlx);
	return (0);
}
