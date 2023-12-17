/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:02:06 by rlevilla          #+#    #+#             */
/*   Updated: 2023/12/17 20:03:00 by rlevilla         ###   ########.fr       */
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
