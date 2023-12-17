/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:04:20 by rlevilla          #+#    #+#             */
/*   Updated: 2023/12/17 20:05:42 by rlevilla         ###   ########.fr       */
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

typedef struct	s_objet
{
	int		type;
	double 	radius;
	double	height;
	double	intensity;
	t_vect	color;
	t_vect	orient;
	t_vect	pos;
}t_objet;


typedef struct	s_sphere
{
	t_vect	pos;
	double	radius;
}t_sphere;

typedef struct	s_cam
{
	t_vect	pos;
	t_vect	dir; // normalize the vector
	double	zoom;
}t_cam;

typedef struct	s_scene
{
	/*t_objet	cam;
	t_objet	light;
	t_objet	ambiant_l;
	t_objet	*objets;*/
	
}t_scene;

void		my_mlx_pixel_put(t_img *map, int x, int y, int color);
double long	ft_atol(char *str);
char		*str_cpy_double_format(char *str);
#endif
