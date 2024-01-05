/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:06:59 by rlevilla          #+#    #+#             */
/*   Updated: 2024/01/03 21:27:44 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sp	*create_sphere(t_vect *origin, double radius)
{
	t_sp	*new_sphere;

	new_sphere = (t_sp *)malloc(sizeof(t_sp) * 1);
	if (!new_sphere)
		return (err_malloc());
	new_sphere->center = create_vect(origin->x, origin->y, origin->z);
	new_sphere->radius = radius;
	return  (new_sphere);
}

t_cam	*new_cam(t_vect *origin, t_vect *dir, double fov)
{
	t_cam	*new_cam;

	new_cam = (t_cam *)malloc(sizeof(t_cam));
	if (!new_cam)
		return (err_malloc());
	new_cam->origin = create_vect(origin->x, origin->y, origin->z);
	new_cam->dir - create_vect(dir->x, dir->y, dir->z);
	new_cam->fov = fov;
	return (new_cam);
}
