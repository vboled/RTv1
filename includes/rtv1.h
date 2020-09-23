/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:35:00 by gweasley          #+#    #+#             */
/*   Updated: 2020/09/16 14:35:03 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <limits.h>
# define WIDTH 600
# define HEIGHT 600

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_light
{
	double			x;
	double			y;
	double			z;
}					t_light;

typedef struct      s_camera
{
	double			x;
	double			y;
	double			z;
	double			tilt_x;
	double			tilt_y;
	double			tilt_z;
}					t_camera;

typedef struct		s_obj
{
	int				type;
	double			x;
	double			y;
	double			z;
	double			scale;
	double			tilt_x;
	double			tilt_y;
	double			tilt_z;
	int				color;
	struct s_obj	*head;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_rtv
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*pix_m;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_obj			*objects;
	t_camera		camera;
	t_light			light;
}					t_rtv;

int					getData(char *filename, t_rtv *scene);
int					addCamera(t_rtv *scene, char **param);
int					addLight(t_rtv *scene, char **param);
int					addObj(t_obj **obj, char **param, int type);
int					deal_hook(int key, t_rtv *param);
void				clear_window(t_rtv *frac);
void				create_mlx_image(t_rtv *frac);
void				tracer(t_rtv *rtv);
#endif
