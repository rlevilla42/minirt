/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:04:20 by rlevilla          #+#    #+#             */
/*   Updated: 2024/01/05 14:47:56 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_INT -2147483648
#define W_WIDTH 800.0
#define W_HEIGHT 400.0
// copie fdf function c tout

typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}t_vect;

typedef	struct	s_img
{
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
	void	*win_ptr;
	t_vect	*color;
}t_img;

/*
typedef struct	s_objet
{
	int		type;
	double 	radius;
	double	height;
	double	intensity;
	double	zoom;
	t_vect	color;
	t_vect	dir;
	t_vect	pos;
}t_objet;
*/
typedef struct	s_a
{
	double	light_ratio;
	t_vect	*color;
}t_a;

typedef struct	s_cam
{
	t_vect	*origin;
	t_vect	*dir; // normalize the vector
	double	fov;
	//double	zoom;
}t_cam;

typedef struct	s_light
{
	t_vect	*light_point;
	double	br_ratio;
}t_light;

typedef struct	s_sp
{
	t_vect	*center;
	double	radius;
	t_vect	*color;
}t_sp;

typedef struct	s_pl
{
	t_vect	*p_plane;
	t_vect	*norm_vect;
	t_vect	*color;
}t_pl;

typedef struct	s_cy
{
	t_vect	*center;
	t_vect	*norm_vect;
	double	radius;
	double 	height;
	t_vect	*color;
}t_cy;

typedef struct	s_scene
{
	t_a		*a;
	t_cam	*cam;
	t_light	*light;
	t_sp	*sp;
	t_pl	*pl;
	t_cy	*cy;
	t_img	*map;
	//t_objet	*objets;
	
}t_scene;

void		my_mlx_pixel_put(t_img *map, int x, int y, int color);
double long	ft_atol(char *str);
char		*str_cpy_double_format(char *str);
int			parsing_a(char **step, t_a *a);
double long	ft_atod(char *str);
t_vect		*fill_vector(char **src, t_vect *vect);
int			parsing_c(char **step, t_cam *c);
int			parsing_l(char **step, t_light *l);
int			parsing_sp(char **step, t_sp *sp);
int			parsing_pl(char **step, t_pl *pl);
int			parsing_cy(char **step, t_cy *cy);
int			close_win(int key, t_img *data);
int			key_hook(int key, t_img *data);
int			norm_vect(t_vect *v);
t_vect		*create_vect(double x, double y, double z);
int			get_color_v(t_vect *color);
int			get_color_d(double x, double y, double z);
void		ft_create_obj(t_scene *sc);
double		vect_lenght(t_vect *v);
int			norm_vect(t_vect *v);
t_vect		*create_vect(double x, double y, double z);
t_vect		*vect_sub(t_vect *v1, t_vect *v2);
double		vect_dot_product(t_vect *v1, t_vect *v2);
t_sp	*create_sphere(t_vect *origin, double radius);
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
;
#endif
