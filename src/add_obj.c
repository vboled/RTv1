/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:34:41 by gweasley          #+#    #+#             */
/*   Updated: 2020/09/16 14:34:43 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

int		get_sphere_param(t_obj *sphere, char **param)
{
	if (!param[7])
		return (0);
	sphere->type = 1;
	sphere->point.x = ft_atoi(param[1]);
	sphere->point.y = ft_atoi(param[2]);
	sphere->point.z = ft_atoi(param[3]);
	sphere->scale = ft_atoi(param[4]);
	sphere->color = ft_atoi(param[5]);
	sphere->specular = ft_atoi(param[6]);
	sphere->reflective = ft_atoi(param[7]) / 100.0;
	if (sphere->reflective > 1.0)
		sphere->reflective = 1.0;
	if (sphere->reflective < 0)
		sphere->reflective = 0.0;
	return (1);
}

int		get_cone_param(t_obj *obj, char **param)
{
	obj->type = 3;
	if (!param[10])
		return (0);
	obj->point.x = ft_atoi(param[1]);
	obj->point.y = ft_atoi(param[2]);
	obj->point.z = ft_atoi(param[3]);
	obj->dir.x = ft_atoi(param[4]);
	obj->dir.y = ft_atoi(param[5]);
	obj->dir.z = ft_atoi(param[6]);
	vec_norm(&obj->dir);
	obj->angle = ft_atoi(param[7]) / 100;
	obj->color = ft_atoi(param[8]);
	obj->specular = ft_atoi(param[9]);
	obj->reflective = ft_atoi(param[10]) / 100.0;
	if (obj->reflective > 1.0)
		obj->reflective = 1.0;
	if (obj->reflective < 0)
		obj->reflective = 0.0;
	return (1);
	return (1);
}

int		get_cylinder_param(t_obj *obj, char **param)
{
	if (!param[10])
		return (0);
	obj->type = 4;
	obj->point.x = ft_atoi(param[1]);
	obj->point.y = ft_atoi(param[2]);
	obj->point.z = ft_atoi(param[3]);
	obj->dir.x = ft_atoi(param[4]);
	obj->dir.y = ft_atoi(param[5]);
	obj->dir.z = ft_atoi(param[6]);
	vec_norm(&obj->dir);
	obj->scale = ft_atoi(param[7]);
	obj->color = ft_atoi(param[8]);
	obj->specular = ft_atoi(param[9]);
	obj->reflective = ft_atoi(param[10]) / 100.0;
	if (obj->reflective > 1.0)
		obj->reflective = 1.0;
	if (obj->reflective < 0)
		obj->reflective = 0.0;
	return (1);
}

int		get_obj_param(t_obj *obj, char **param, int type)
{
	if (type == 1 && !get_sphere_param(obj, param))
		return (0);
	if (type == 2 && !get_plane_param(obj, param))
		return (0);
	if (type == 3 && !get_cone_param(obj, param))
		return (0);
	if (type == 4 && !get_cylinder_param(obj, param))
		return (0);
	return (1);
}

int		add_obj(t_obj **obj, char **param, int type)
{
	t_obj	*tmp;

	if (!(*obj))
	{
		if (!(*obj = (t_obj *)malloc(sizeof(t_obj))))
			return (0);
		(*obj)->next = 0;
		if (!get_obj_param(*obj, param, type))
			return (0);
		return (1);
	}
	tmp = *obj;
	while ((*obj)->next)
		*obj = (*obj)->next;
	if (!((*obj)->next = (t_obj *)malloc(sizeof(t_obj))))
		return (0);
	*obj = (*obj)->next;
	if (!get_obj_param(*obj, param, type))
		return (0);
	*obj = tmp;
	return (1);
}
