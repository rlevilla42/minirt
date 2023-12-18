/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:12:06 by rlevilla          #+#    #+#             */
/*   Updated: 2023/12/17 22:58:35 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 47 || str[i] > 57)
			return (-1);
		else
			i++;
	}
	return (0);
}

int	check_neg(char *str)
{
	int	countminus;

	countminus = 1;
	if (str[0] == '-')
		countminus = -1;
	return (countminus);
}

int	flag_double_or_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 46)
			return (i + 1);
		i++;
	}
	return (0);
}

double	ft_decimal(char *str)
{
	int		i;
	double	double_size;
	double	count;
	double	decimal;

	i = 0;
	double_size = ft_strlen(str);
	decimal = 0;
	count = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		decimal = (decimal * 10) + (str[i] - 48);
		i++;
	}
	while (double_size > 0)
	{
		decimal /= 10;
		double_size--;
	}
	return (decimal);
}

double long	ft_atod(char *str)
{
	int			i;
	int			index;
	int			countminus;
	long double	buffer;
	long double	buffer2;

	i = 0;
	index = flag_double_or_int(str);
	countminus = check_neg(str);
	buffer = 0;
	buffer2 = 0;
	if (flag_double_or_int(str) == 0)
		str = str_cpy_double_format(str);
	if (countminus == -1)
		i++;
	if (index == 0)
		return (ft_atol(&str[i]) * countminus);
	else
		buffer = ft_atol(&str[i]);
	buffer2 = (ft_decimal(&str[index]));
	if (buffer >= 0)
		buffer += buffer2;
	else
		buffer -= buffer2;
	return (buffer * countminus);
}
/*
int main(void)
{
	printf("2147483647.0 = %Lf\n", ft_atod("2147483647.0"));
	printf("-2147483648.0 = %Lf\n", ft_atod("-2147483648.0"));
	printf("2147483655 = %Lf\n", ft_atod("2147483655"));
	printf("-2147483655 = %Lf\n", ft_atod("-2147483655"));

	printf("-214.0 = %Lf\n", ft_atod("-214.0"));
	printf("-214 = %Lf\n", ft_atod("-214"));
	printf("2147483649 = %Lf\n", ft_atod("2147483649"));
	printf("-2147483649 = %Lf\n\n", ft_atod("-2147483649"));
	printf("-0.91 = %Lf\n", ft_atod("-0.91"));
	printf("0.91 = %Lf\n", ft_atod("0.91"));
	printf("-78.123 = %Lf\n", ft_atod("-78.123"));
	printf("78.123 = %Lf\n", ft_atod("78.123"));
	printf("-938123.667 = %Lf\n", ft_atod("-938123.667"));
	printf("938123.667 = %Lf\n", ft_atod("938123.667"));
}*/
