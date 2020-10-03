/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:34:11 by gweasley          #+#    #+#             */
/*   Updated: 2020/09/16 14:34:34 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		addObject(t_rtv *scene, char **param)
{
	if (param[0] == NULL)
		return (0);
	if (!ft_strcmp(param[0], "camera:"))
		return (addCamera(scene, param));
	else if (!ft_strcmp(param[0], "sphere:"))
		return (addObj(&(scene->objects), param, 1));
	else if (!ft_strcmp(param[0], "light:"))
		return (addLight(&(scene->lights), param));
	else if (!ft_strcmp(param[0], "plane:"))
		return (addObj(&(scene->objects), param, 2));
	else if (!ft_strcmp(param[0], "cone:"))
		return (addObj(&(scene->objects), param, 3));
	return (1);
}

void	init_mlx(t_rtv *rtv)
{
	rtv->mlx = mlx_init();
	rtv->win = mlx_new_window(rtv->mlx, WIDTH, HEIGHT + 85, "win1");
	rtv->img = mlx_new_image(rtv->mlx, WIDTH, HEIGHT);
	mlx_string_put(rtv->mlx, rtv->win, 1, 5, 0xFFFFFF,
	"Use the arrows to rotate the camera");
	mlx_string_put(rtv->mlx, rtv->win, 1, 25, 0xFFFFFF,
	"Use A/D to move the camera along the axis x");
	mlx_string_put(rtv->mlx, rtv->win, 1, 45, 0xFFFFFF,
	"Use W/S to move the camera along the axis y");
	mlx_string_put(rtv->mlx, rtv->win, 1, 65, 0xFFFFFF,
	"Use Space/LCtrl to move the camera along the axis z");
}

int		getData(char *filename, t_rtv *scene)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (!ret)
		{
			free(line);
			close(fd);
			break ;
		}
		if (ret == -1 || !addObject(scene, ft_strsplit(line, ' ')))
		{
			close(fd);
			return (0);
		}
		free(line);
	}
	init_mlx(scene);
	return (1);
}
