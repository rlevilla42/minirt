/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <rlevilla@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:03:34 by rlevilla          #+#    #+#             */
/*   Updated: 2024/01/05 15:20:25 by rlevilla         ###   ########.fr       */
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
/*
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
*/
void	setupscene(t_scene *sc)
{
	sc->cam->origin = create_vect(0.0, 0.f, 3.5);
	sc->cam->dir = create_vect(0.0, 0.0, -1.0);
	sc->sp->center = create_vect(0.0, 0.0, 0.0);
	sc->sp->radius = 0.3;
}

void	draw_sphere(t_img *map, t_vect *sp_origin, double radius)
{
	double	i;
	double	j;

	i = -radius;
	j = -radius;
	while (i < radius)
	{
		j = radius * (-1);
		while (j < radius)
		{
			if (i * i + j * j <= radius * radius)
			{
				my_mlx_pixel_put(map, sp_origin->x + i, sp_origin->y + j, get_color_v(map->color));
			}
			j++;
		}
		i++;
	}
}

void	draw_background(t_img *map)
{
	double	i = 0.0;
	double	j = 0.0;
	while (j < W_HEIGHT)
	{
		i = 0;
		while (i < W_WIDTH)
		{
			double r = (i / W_WIDTH);
			double g = (j / W_HEIGHT);
			double b = 0.2;
			my_mlx_pixel_put(map, i, j, get_color_d(r, g, b));
			i++;
		}
		j++;
	}
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	i;
	int	j;
	t_img	*map;
	//t_vect	*color;
	t_scene	*sc;

	i = 0;
	j = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, W_WIDTH, W_HEIGHT, "MACRON_DEMISSION");
	map = (t_img *)malloc(sizeof(t_img));
	map->img = mlx_new_image(mlx_ptr, W_WIDTH, W_HEIGHT);
	map->img_addr = mlx_get_data_addr(map->img, &map->bits_per_pixel,
			&map->line_length, &map->endian);
	map->mlx_ptr = mlx_ptr;
	map->win_ptr = win_ptr;
	sc = (t_scene *)malloc(sizeof(t_scene));
	ft_create_obj(sc);
	map->color = create_vect(0.3, 0.5, 0.1);
	sc->sp->center = create_vect(W_WIDTH/2.0, W_HEIGHT/2.0, 500.0);
	draw_background(map);
	draw_sphere(map, sc->sp->center, 100.0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, map->img, 0, 0);
	mlx_hook(map->win_ptr, 17, 0, close_win, map);
	mlx_hook(map->win_ptr, 2, 0, key_hook, map);	
	mlx_loop(map->mlx_ptr);
	return (0);
}

/*
#include "mlx.h"
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct
{
    double x;
    double y;
    double z;
} Vector3D;

typedef struct
{
    Vector3D center;
    double radius;
} Sphere;

typedef struct
{
    double x;
    double y;
    double z;
} Light;

void put_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int color)
{
    mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
}

int calculate_shading(Vector3D point, Vector3D light)
{
    double distance = sqrt(pow(point.x - light.x, 2) + pow(point.y - light.y, 2) + pow(point.z - light.z, 2));
    double intensity = 1.0 / distance; // Simple intensity calculation

    // Limit intensity to the range [0, 1]
    intensity = fmax(0.0, fmin(1.0, intensity));

    return (int)(intensity * 255);
}

void draw_sphere(void *mlx_ptr, void *win_ptr, Sphere sphere)
{
    double phi, theta;
    int screen_x, screen_y;
	int color = 0xFF1493;

    for (phi = 0; phi <= M_PI; phi += 0.01)
    {
        for (theta = 0; theta <= 2 * M_PI; theta += 0.01)
        {
            screen_x = (int)(sphere.center.x + sphere.radius * sin(phi) * cos(theta));
            screen_y = (int)(sphere.center.y + sphere.radius * sin(phi) * sin(theta));

            put_pixel(mlx_ptr, win_ptr, screen_x, screen_y, color);
        }
    }
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    Sphere my_sphere = {{WIDTH / 2, HEIGHT / 2, 0}, 50}; // Center of the window

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Shaded Sphere Drawing");

    draw_sphere(mlx_ptr, win_ptr, my_sphere);

    mlx_loop(mlx_ptr);

    return 0;
}
*/
