/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:20:00 by rlevilla          #+#    #+#             */
/*   Updated: 2024/01/03 21:02:42 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vect_lenght(t_vect *v)
{
	double	lenght;

	lenght = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	return (lenght);
}

int	norm_vect(t_vect *v)
{
	double	lenght;

	lenght = vect_lenght(v);;
	if (lenght < 0)
		return (-1);
	v->x /= lenght;
	v->y /= lenght;
	v->z /= lenght;
	return (0);
}

t_vect	*create_vect(double x, double y, double z)
{
	t_vect *v;

	v = (t_vect *)malloc(sizeof(t_vect));
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vect	*vect_sub(t_vect *v1, t_vect *v2)
{
	t_vect *new_vect;

	new_vect = create_vect(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
	return (new_vect);
}

double	vect_dot_product(t_vect *v1, t_vect *v2)
{
	double	result;

	result = (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
	return (result);
}
