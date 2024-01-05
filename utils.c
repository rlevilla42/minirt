/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:02:06 by rlevilla          #+#    #+#             */
/*   Updated: 2024/01/05 15:20:28 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*str_cpy_double_format(char *str)
{
	int		size;
	int		i;
	char	*cpy;

	size = ft_strlen(str);
	cpy = malloc((sizeof(char) * size) + 2);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '.';
	cpy[++i] = '0';
	return (cpy);
}

double long	ft_atol(char *str)
{
	int			i;
	double long	buffer;
	int			countminus;

	i = 0;
	countminus = 1;
	buffer = 0.0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			countminus = -1;
		i++;
	}
	if (str[i] < 48 || str[i] > 57)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		buffer = (buffer * 10) + (str[i] - 48);
		i++;
	}
	return (buffer * countminus);
}

double	check_minmax(double n, double min, double max)
{
	if (n <= min)
		return (min);
	if (n >= max)
		return (max);
	return (n);
}

int	get_color_v(t_vect *color)
{
	int	x;
	int	y;
	int	z;

	x = check_minmax(color->x, 0.0, 1.0) * 255.0;
	y = check_minmax(color->y, 0.0, 1.0) * 255.0;
	z = check_minmax(color->z, 0.0, 1.0) * 255.0;
    return ((x << 16) | (y << 8) | z);
}

int	get_color_d(double x, double y, double z)
{
	int	x1;
	int	y1;
	int	z1;

	x1 = check_minmax(x, 0.0, 1.0) * 255.99;
	y1 = check_minmax(y, 0.0, 1.0) * 255.99;
	z1 = check_minmax(z, 0.0, 1.0) * 255.99;
    return ((x1 << 16) | (y1 << 8) | z1);
}

void	err_malloc()
{
	write(2, "Malloc error\n", 13);
	exit(1);
}
