/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:44:21 by rlevilla          #+#    #+#             */
/*   Updated: 2023/12/17 20:02:58 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parsing(char **argv)
{
	int		fd;
	char	*line;
	if (open(argv[1], O_RDONLY) < 0)
		return (-1);
	lien = get_next_line(fd);
	while (line 
}
