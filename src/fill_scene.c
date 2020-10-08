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

int		is_valid_str(char **str)
{
	int i;
	int	j;

	if (!str[0])
		return (0);
	if (!ft_strcmp(str[0], "light:"))
		i = 2;
	else
		i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if ((str[i][j] < '0' || str[i][j] > '9') && str[i][j] != '-')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		add_object(t_rtv *scene, char **param)
{
	if (!is_valid_str(param))
		return (0);
	if (!ft_strcmp(param[0], "camera:"))
		return (add_camera(scene, param));
	else if (!ft_strcmp(param[0], "sphere:"))
		return (add_obj(&(scene->objects), param, 1));
	else if (!ft_strcmp(param[0], "light:"))
		return (add_light(&(scene->lights), param));
	else if (!ft_strcmp(param[0], "plane:"))
		return (add_obj(&(scene->objects), param, 2));
	else if (!ft_strcmp(param[0], "cone:"))
		return (add_obj(&(scene->objects), param, 3));
	else if (!ft_strcmp(param[0], "cylinder:"))
		return (add_obj(&(scene->objects), param, 4));
	return (1);
}

int		init_mlx(t_rtv *rtv)
{
	if (!(rtv->mlx = mlx_init()))
		return (0);
	if (!(rtv->win = mlx_new_window(rtv->mlx, WIDTH, HEIGHT + 85, "win1")))
		return (0);
	if (!(rtv->img = mlx_new_image(rtv->mlx, WIDTH, HEIGHT)))
		return (0);
	mlx_string_put(rtv->mlx, rtv->win, 1, 5, 0xFFFFFF,
	"Use the arrows to rotate the camera");
	mlx_string_put(rtv->mlx, rtv->win, 1, 45, 0xFFFFFF,
	"Use W/S to move the camera");
	return (1);
}

int		get_data(char *filename, t_rtv *scene)
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
		if (ret == -1 || !add_object(scene, ft_strsplit(line, ' ')))
		{
			close(fd);
			return (0);
		}
		free(line);
	}
	if (!init_mlx(scene))
		return (0);
	return (1);
}
