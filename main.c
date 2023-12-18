/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:03:34 by rlevilla          #+#    #+#             */
/*   Updated: 2023/12/18 20:03:34 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_img *map, int x, int y, int color)
{
	char	*dst;

	dst = map->img_addr + (y * map->line_length
			+ x *(map->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

int	intersection(void)
{
	return (0);
}

void	raytracing(t_color *color)
{
	if (intersection() == 0)
	{
		color->col = 0xFFFFFF;
	}
}

void	setupscene(void)
{
	t_cam	cam;
	t_sphere	sphere;

	cam.pos.x = 0.0;
	cam.pos.y = 0.1;
	cam.pos.z = 3.5;

	cam.dir.x = 0.0;
	cam.dir.y = 0.0;
	cam.dir.z = -1.0;

	cam.zoom = 1.0;

	sphere.pos.x = 0.0;
	sphere.pos.y = 0.0;
	sphere.pos.z = 0.0;
	sphere.radius = 0.3;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	map;
	t_color	*color;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 889, 500, "MACRON_DEMISSION");
	map.img = mlx_new_image(mlx_ptr, 889, 500);
	map.img_addr = mlx_get_data_addr(map.img, &map.bits_per_pixel,
			&map.line_length, &map.endian);
	color = (t_color *)malloc(sizeof(t_color));
	color->col = 0xFF1493;
	setupscene();
	// code
	
  	mlx_put_image_to_window(mlx_ptr, win_ptr, map.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
