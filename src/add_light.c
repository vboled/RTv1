#include "rtv1.h"

int		getAmbientLightParam(t_light *light, char **param)
{
	light->type = 1;
	if (!param[2])
		return (0);
	light->intens = ft_atoi(param[2]) / 100.0;
	return (1);
}

int		getPointLightParam(t_light *light, char **param)
{
	light->type = 2;
	if (!param[5])
		return (0);
	light->intens = ft_atoi(param[2]) / 100.0;
	light->x = ft_atoi(param[3]);
	light->y = ft_atoi(param[4]);
	light->z = ft_atoi(param[5]);
	return (1);
}

int		getDirectionalLightParam(t_light *light, char **param)
{
	light->type = 3;
	if (!param[5])
		return (0);
	light->intens = ft_atoi(param[2]) / 100.0;
	light->dirX = ft_atoi(param[3]);
	light->dirY = ft_atoi(param[4]);
	light->dirZ = ft_atoi(param[5]);
	return (1);
}

int		getLightParam(t_light *light, char **param)
{
	if (!param[1])
		return (0);
	if (!ft_strcmp(param[1], "ambient") && !getAmbientLightParam(light, param))
		return (0);
	else if (!ft_strcmp(param[1], "point") && !getPointLightParam(light, param))
		return (0);
	else if (!ft_strcmp(param[1], "directional") && !getDirectionalLightParam(light, param))
		return (0);
	return (1);
}

int		addLight(t_light **light, char **param)
{
	t_light	*tmp;

	if (!(*light))
	{
		if (!(*light = (t_light *)malloc(sizeof(t_light))))
			return (0);
		(*light)->next = 0;
		if (!getLightParam(*light, param))
			return (0);
		return (1);
	}
	tmp = *light;
	while ((*light)->next)
		*light = (*light)->next;
	if (!((*light)->next = (t_light *)malloc(sizeof(t_light))))
		return (0);
	*light = (*light)->next;
	if (!getLightParam(*light, param))
		return (0);
	*light = tmp;
	return (1);
}