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
	double			dir_x;
	double			dir_y;
	double			dir_z;
	double			intens;
	int				type;
	struct s_light	*next;
}					t_light;

typedef struct		s_camera
{
	t_vec			pos;
	double			tilt_x;
	double			tilt_y;
}					t_camera;

typedef struct		s_obj
{
	int				type;
	t_vec			dir;
	t_vec			point;
	double			angle;
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
	int				need_to_redraw;
}					t_rtv;

void				memory_free(t_rtv *rtv);
int					get_data(char *filename, t_rtv *scene);
int					add_camera(t_rtv *scene, char **param);
int					add_light(t_light **light, char **param);
int					deal_hook(int key, t_rtv *param);
void				clear_window(t_rtv *frac);
void				create_mlx_image(t_rtv *frac);
void				vec_init(t_vec *d, int x, int y);
void				tracer(t_rtv *rtv);
void				make_n(t_rtv *rtv);
void				make_p(t_rtv *rtv);
int					make_l(t_vec *l, t_light *head, t_vec *p, double *max);
double				dot(t_vec *lhs, t_vec *rhs);
double				vec_len(t_vec *vec);
int					is_shadow(t_rtv *rtv, double min, double max, t_light *light);
t_vec				reverse_vec(t_vec *vec);
int					add_camera(t_rtv *scene, char **param);
void				intersect_plane(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj);
double				sq(double num);
void				calculate_t(t_rtv *rtv, double k1, double k2, double k3);
void				intersect_obj(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj);
void				vec_rot(t_rtv *rtv, t_vec *d);
void				make_n(t_rtv *rtv);
t_vec				vec_dif(const t_vec *lhs, const t_vec *rhs);
void				vec_copy(const t_vec *source, t_vec *dist);
void				vec_norm(t_vec *vec);
t_vec				vec_mult_num(const t_vec *vec, double num);
int					add_obj(t_obj **obj, char **param, int type);
int					get_plane_param(t_obj *obj, char **param);
void				intersect_cone(t_rtv *rtv, t_vec *o, t_vec *d, t_obj *obj);
int					closest_intersection(t_rtv *rtv, t_vec *o, t_vec *d, 
					double min);
#endif
