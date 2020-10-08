/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:09:12 by gweasley          #+#    #+#             */
/*   Updated: 2020/10/08 16:09:14 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_ambient_light_param(t_light *light, char **param)
{
	light->type = 1;
	if (!param[2])
		return (0);
	light->intens = ft_atoi(param[2]) / 100.0;
	if (light->intens > 1.0)
		light->intens = 1.0;
	return (1);
}

int		get_point_light_param(t_light *light, char **param)
{
	light->type = 2;
	if (!param[5])
		return (0);
	light->intens = ft_atoi(param[2]) / 100.0;
	if (light->intens > 1.0)
		light->intens = 1.0;
	light->x = ft_atoi(param[3]);
	light->y = ft_atoi(param[4]);
	light->z = ft_atoi(param[5]);
	return (1);
}

int		get_directional_light_param(t_light *light, char **param)
{
	light->type = 3;
	if (!param[5])
		return (0);
	light->intens = (double)ft_atoi(param[2]) / 100.0;
	if (light->intens > 1.0)
		light->intens = 1.0;
	light->dir_x = ft_atoi(param[3]);
	light->dir_y = ft_atoi(param[4]);
	light->dir_z = ft_atoi(param[5]);
	return (1);
}

int		get_light_param(t_light *light, char **param)
{
	if (!param[1])
		return (0);
	if (!ft_strcmp(param[1], "ambient") &&
		!get_ambient_light_param(light, param))
		return (0);
	else if (!ft_strcmp(param[1], "point") &&
		!get_point_light_param(light, param))
		return (0);
	else if (!ft_strcmp(param[1], "directional") &&
		!get_directional_light_param(light, param))
		return (0);
	return (1);
}

int		add_light(t_light **light, char **param)
{
	t_light	*tmp;

	if (!(*light))
	{
		if (!(*light = (t_light *)malloc(sizeof(t_light))))
			return (0);
		(*light)->next = 0;
		if (!get_light_param(*light, param))
			return (0);
		return (1);
	}
	tmp = *light;
	while ((*light)->next)
		*light = (*light)->next;
	if (!((*light)->next = (t_light *)malloc(sizeof(t_light))))
		return (0);
	*light = (*light)->next;
	if (!get_light_param(*light, param))
		return (0);
	*light = tmp;
	return (1);
}
