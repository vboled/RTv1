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

int		addCamera(t_rtv *scene, char **param)
{
	if (param[1])
		scene->camera.x = ft_atoi(param[1]);
	if (param[2])
		scene->camera.y = ft_atoi(param[2]);
	if (param[3])
		scene->camera.z = ft_atoi(param[3]);
	return (1);
}

int		getSphereParam(t_obj *sphere, char **param)
{
	if (!param[8])
		return (0);
	sphere->type = 1;
	sphere->x = ft_atoi(param[1]);
	sphere->y = ft_atoi(param[2]);
	sphere->z = ft_atoi(param[3]);
	sphere->scale = ft_atoi(param[4]);
	sphere->tilt_x = ft_atoi(param[5]);
	sphere->tilt_y = ft_atoi(param[6]);
	sphere->tilt_z = ft_atoi(param[7]);
	sphere->color = ft_atoi(param[8]);
	return (1);
}

int		getObjParam(t_obj *obj, char **param, int type)
{
	if (type == 1 && !getSphereParam(obj, param))
		return (0);
	return (1);
}

int		addObj(t_obj **obj, char **param, int type)
{
	t_obj	*tmp;

	if (!(*obj))
	{
		if (!(*obj = (t_obj *)malloc(sizeof(t_obj))))
			return (0);
		(*obj)->next = 0;
		if (!getObjParam(*obj, param, type))
			return (0);
		return (1);
	}
	tmp = *obj;
	while ((*obj)->next)
		*obj = (*obj)->next;
	if (!((*obj)->next = (t_obj *)malloc(sizeof(t_obj))))
		return (0);
	*obj = (*obj)->next;
	if (!getObjParam(*obj, param, type))
		return (0);
	*obj = tmp;
	return (1);
}
