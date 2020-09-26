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
# define MAX_T 2147483647
# define MIN_T 1
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
	double			dirX;
	double			dirY;
	double			dirZ;
	double			intens;
	int				type;
	struct s_light	*next;
}					t_light;

typedef struct      s_camera
{
	t_vec			pos;
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
	double			specular;
	double			reflective;
	int				color;
	struct s_obj	*next;
}					t_obj;


typedef	struct		s_closest
{
	t_obj			*obj;
	double			t;
}					t_closest;

typedef struct		s_rtv
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*pix_m;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				*depth;
	t_vec			n;
	t_vec			l;
	t_vec			p;
	t_vec			d;
	t_obj			*objects;
	t_camera		camera;
	t_closest		*closest;
	t_light			*lights;
	double			t1;
	double			t2;
}					t_rtv;

int					getData(char *filename, t_rtv *scene);
int					addCamera(t_rtv *scene, char **param);
int					addLight(t_light **light, char **param);
int					addObj(t_obj **obj, char **param, int type);
int					deal_hook(int key, t_rtv *param);
void				clear_window(t_rtv *frac);
void				create_mlx_image(t_rtv *frac);
void				vecInit(t_vec *d, int x, int y);
void				tracer(t_rtv *rtv);
void				make_n(t_rtv *rtv);
void				make_p(t_rtv *rtv);
int					make_l(t_vec *l, t_light *head, t_vec *p);
double				dot(t_vec *lhs, t_vec *rhs);
double				vec_len(t_vec *vec);
int					is_shadow(t_rtv *rtv);
t_vec				reverse_vec(t_vec *vec);
int					closest_intersection(t_rtv *rtv, t_vec *o, t_vec *d, double min);
#endif
