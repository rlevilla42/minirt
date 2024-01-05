/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:37:39 by rlevilla          #+#    #+#             */
/*   Updated: 2023/12/23 18:19:39 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_win(int key, t_img *data)
{
	if (key == 53)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	key_hook(int key, t_img *data)
{
	if (key == 53)
		close_win(key, data);
	exit(0);
}
