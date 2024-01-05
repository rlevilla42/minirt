/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:53:12 by rlevilla          #+#    #+#             */
/*   Updated: 2024/01/04 19:36:20 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parsing_c(char **step, t_cam *c)
{
	int		i;
	int		i2;
	char	**last_split;

	i = 1;
	i2 = 0;
	last_split = ft_split(step[1], ',');
	if (last_split == NULL)
		return (-1);
	c->origin = fill_vector(last_split, c->origin);
	if (last_split == NULL)
		return (-1);
	last_split = ft_split(step[2], ',');
	c->dir = fill_vector(last_split, c->dir);
	c->fov = ft_atod(step[3]);
	return (0);
}

int	parsing_l(char **step, t_light *l)
{
	int		i;
	int		i2;
	char	**last_split;

	i = 1;
	i2 = 0;
	last_split = ft_split(step[1], ',');
	if (last_split == NULL)
		return (-1);
	l->light_point = fill_vector(last_split, l->light_point);
	/*printf("l->light_point->x = %f\n", l->light_point->x);
	printf("l->light_point->y = %f\n", l->light_point->y);
	printf("l->light_point->z = %f\n", l->light_point->z);*/
	l->br_ratio = ft_atod(step[2]);
	//printf("l->br_ration = %f\n", l->br_ratio);
	return (0);
}

int	parsing_sp(char **step, t_sp *sp)
{
	int		i;
	int		i2;
	char	**last_split;

	i = 1;
	i2 = 0;
	last_split = ft_split(step[1], ',');
	if (last_split == NULL)
		return (-1);
	sp->center = fill_vector(last_split, sp->center);
	/*printf("sp->center->x = %f\n", sp->center->x);
	printf("sp->center->y = %f\n", sp->center->y);
	printf("sp->center->z = %f\n", sp->center->z);*/
	sp->radius = ft_atod(step[2]);
	//printf("sp->radius= %f\n", sp->radius);
	sp->color = fill_vector(last_split, sp->color);
	return (0);
}

int	parsing_pl(char **step, t_pl *pl)
{
	int		i;
	int		i2;
	char	**last_split;

	i = 1;
	i2 = 0;
	last_split = ft_split(step[1], ',');
	if (last_split == NULL)
		return (-1);
	pl->p_plane = fill_vector(last_split, pl->p_plane);
	last_split = ft_split(step[2], ',');
	if (last_split == NULL)
		return (-1);
	pl->norm_vect = fill_vector(last_split, pl->norm_vect);
	last_split = ft_split(step[3], ',');
	if (last_split == NULL)
		return (-1);
	pl->color = fill_vector(last_split, pl->color);
	/*printf("pl->p_plane->x = %f\n", pl->p_plane->x);
	printf("pl->p_plane->y = %f\n", pl->p_plane->y);
	printf("pl->p_plane->z = %f\n", pl->p_plane->z);
	printf("pl->norm_vect->x = %f\n", pl->norm_vect->x);
	printf("pl->norm_vect->y = %f\n", pl->norm_vect->y);
	printf("pl->norm_vect->z = %f\n", pl->norm_vect->z);
	printf("pl->color->x = %f\n", pl->color->x);
	printf("pl->color->y = %f\n", pl->color->y);
	printf("pl->color->z = %f\n", pl->color->z);*/
	return (0);
}

int	parsing_cy(char **step, t_cy *cy)
{
	int		i;
	int		i2;
	char	**last_split;

	i = 1;
	i2 = 0;
	last_split = ft_split(step[1], ',');
	if (last_split == NULL)
		return (-1);
	cy->center = fill_vector(last_split, cy->center);
	last_split = ft_split(step[2], ',');
	if (last_split == NULL)
		return (-1);
	cy->norm_vect = fill_vector(last_split, cy->norm_vect);
	cy->radius = ft_atod(step[3]);
	cy->height = ft_atod(step[4]);
	last_split = ft_split(step[5], ',');
	if (last_split == NULL)
		return (-1);
	cy->color = fill_vector(last_split, cy->color);
	return (0);
}
