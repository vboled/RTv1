/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:09:26 by gweasley          #+#    #+#             */
/*   Updated: 2020/10/08 16:09:28 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_plane_param(t_obj *obj, char **param)
{
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;

	if (!param[9])
		return (0);
	obj->type = 2;
	obj->point.x = ft_atoi(param[1]);
	obj->point.y = ft_atoi(param[2]);
	obj->point.z = ft_atoi(param[3]);
	obj->dir.x = ft_atoi(param[4]);
	obj->dir.y = ft_atoi(param[5]);
	obj->dir.z = ft_atoi(param[6]);
	obj->color = ft_atoi(param[7]);
	obj->specular = ft_atoi(param[7]);
	obj->reflective = ft_atoi(param[9]) / 100.0;
	if (obj->reflective > 1.0)
		obj->reflective = 1.0;
	if (obj->reflective < 0)
		obj->reflective = 0.0;
	return (1);
}

int		add_camera(t_rtv *scene, char **param)
{
	if (param[1])
		scene->camera.pos.x = ft_atoi(param[1]);
	if (param[2])
		scene->camera.pos.y = ft_atoi(param[2]);
	if (param[3])
		scene->camera.pos.z = ft_atoi(param[3]);
	return (1);
}
