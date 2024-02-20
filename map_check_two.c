/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:06:51 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/20 15:31:00 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shape_check(t_map *map_data)
{
	int	x;
	int	y;

	x = 1;
	map_data->width = ft_strlen(map_data->map[0]);
	while (map_data->map[x])
	{
		y = 0;
		while (map_data->map[x][y])
			y++;
		if (y != map_data->width)
			ft_perror("Invalid map shape");
		x++;
	}
	map_data->height = x;
}

void	map_check(t_map *map_data)
{
	shape_check(map_data);
	row_check(map_data);
	column_check(map_data);
	icon_check(map_data);
	valid_path(map_data);
}

t_map	*init_layout(char **map)
{
	t_map	*layout;

	layout = malloc(sizeof(t_map));
	if (!layout)
		ft_perror("Malloc Failure");
	layout->map = map;
	layout->pos_x = 0;
	layout->pos_y = 0;
	layout->n_player = 0;
	layout->exit = 0;
	layout->collect = 0;
	layout->f_collect = 0;
	layout->steps = 1;
	layout->width = 0;
	layout->height = 0;
	return (layout);
}
