/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:06:51 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/13 15:26:26 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shape_check(t_map *layout)
{
	int	x;
	int	y;

	x = 1;
	layout->width = ft_strlen(layout->map[0]);
	while (layout->map[x])
	{
		y = 0;
		while (layout->map[x][y])
			y++;
		if (y != layout->width)
			ft_perror("Invalid map shape");
		x++;
	}
	layout->height = x;
}

void	map_check(t_map *layout)
{
	init_layout(layout);
	shape_check(layout);
	row_check(layout);
	column_check(layout);
	icon_check(layout);
	valid_path(layout);
}

void	init_layout(t_map *layout)
{
	layout->pos_x = 0;
	layout->pos_y = 0;
	layout->n_player = 0;
	layout->exit = 0;
	layout->collect = 0;
	layout->space = 0;
	layout->width = 0;
	layout->height = 0;
}
