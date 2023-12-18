/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:04:20 by rlevilla          #+#    #+#             */
/*   Updated: 2023/12/18 20:03:32 by rlevilla         ###   ########.fr       */
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
// copie fdf function c tout
typedef	struct	s_img
{
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct	s_color
{
	int	col;
}t_color;

typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}t_vect;
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
	t_vect	*view_p;
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
#endif
