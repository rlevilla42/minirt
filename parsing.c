/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:44:21 by rlevilla          #+#    #+#             */
/*   Updated: 2024/01/04 19:34:54 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_create_obj(t_scene *sc)
{
	sc->a = (t_a *)malloc(sizeof(t_a));
	sc->a->color = (t_vect *)malloc(sizeof(t_vect));
	sc->cam = (t_cam *)malloc(sizeof(t_cam));
	sc->cam->origin = (t_vect *)malloc(sizeof(t_vect));
	sc->cam->dir = (t_vect *)malloc(sizeof(t_vect));
	sc->light = (t_light *)malloc(sizeof(t_light));
	sc->light->light_point = (t_vect *)malloc(sizeof(t_vect));
	sc->sp = (t_sp *)malloc(sizeof(t_sp));
	sc->sp->center = (t_vect *)malloc(sizeof(t_vect));
	sc->sp->color = (t_vect *)malloc(sizeof(t_vect));
	sc->pl = (t_pl *)malloc(sizeof(t_pl));
	sc->pl->p_plane = (t_vect *)malloc(sizeof(t_vect));
	sc->pl->norm_vect = (t_vect *)malloc(sizeof(t_vect));
	sc->pl->color = (t_vect *)malloc(sizeof(t_vect));
	sc->cy = (t_cy *)malloc(sizeof(t_cy));
	sc->cy->center = (t_vect *)malloc(sizeof(t_vect));
	sc->cy->norm_vect = (t_vect *)malloc(sizeof(t_vect));
	sc->cy->color = (t_vect *)malloc(sizeof(t_vect));
	sc->map = (t_img *)malloc(sizeof(t_img));
	sc->map->color = (t_vect *)malloc(sizeof(t_vect));
}

t_vect	*fill_vector(char **src, t_vect *vect)
{
	vect->x = ft_atod(src[0]);
	vect->y = ft_atod(src[1]);
	vect->z = ft_atod(src[2]);
	/*printf("vect->x = %f\n", vect->x);
	printf("vect->y = %f\n", vect->y);
	printf("vect->z = %f\n\n", vect->z);*/
	return (vect);
}

int	parsing_a(char **step, t_a *a)
{
	int		i;
	int		i2;
	char	**last_split;
	//(void)a;

	i = 1;
	i2 = 0;
	a->light_ratio = ft_atod(step[i]);
	//a->light_ratio = ft_atod(step[i]);
	last_split = ft_split(step[2], ',');
	if (last_split == NULL)
		return (-1);
	a->color->x = ft_atod(last_split[i2++]);
	a->color->y = ft_atod(last_split[i2++]);
	a->color->z = ft_atod(last_split[i2++]);
	/*printf("a->color->x = %f\n", a->color->x);
	printf("a->color->y = %f\n", a->color->y);
	printf("a->color->z = %f\n\n", a->color->z);*/
	return (0);
}

void	init_scene(char *line, t_scene *sc)
{
	char	**step1;
	int		i;

	i = 0;
	step1 = ft_split(line, ' ');
	/*while (step1[i] != NULL)
	{
		printf("step[%d] = %s\n", i, step1[i]);
		i++;
	}
	i = 0;*/
	if (strcmp(step1[0], "A") == 0)
		parsing_a(step1, sc->a);
	if (strcmp(step1[0], "C") == 0)
		parsing_c(step1, sc->cam);
	if (strcmp(step1[0], "L") == 0)
		parsing_l(step1, sc->light);
	if (strcmp(step1[0], "sp") == 0)
		parsing_sp(step1, sc->sp);
	if (strcmp(step1[0], "pl") == 0)
		parsing_pl(step1, sc->pl);
	if (strcmp(step1[0], "cy") == 0)
		parsing_cy(step1, sc->cy);
	return ;
}

void	parsing(int argc, char **argv, t_scene *sc)
{
	int		fd;
	char	*line;

	ft_create_obj(sc);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || argc != 2)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		init_scene(line, sc);
		line = get_next_line(fd);
	}
	return ;
}
/*
int	main(int argc, char **argv)
{
	//(void)argc, argv;
	t_scene	sc;
	parsing(argc, argv, &sc);
	return (0);
}*/
