/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:34:56 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/21 14:21:29 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	row_check(t_map *map_data)
{
	int	y;

	y = 0;
	while (map_data->map[0][y])
	{
		if (map_data->map[0][y] != WALL)
			ft_perror("Invalid border");
		y++;
	}
	y = 0;
	while (map_data->map[map_data->height - 1][y])
	{
		if (map_data->map[map_data->height - 1][y] != WALL)
			ft_perror("Invalid border");
		y++;
	}
}

void	column_check(t_map *map_data)
{
	int	x;

	x = 0;
	while (map_data->map[x])
	{
		if (map_data->map[x][0] != WALL)
			ft_perror("Invalid border");
		x++;
	}
	x = 0;
	while (map_data->map[x])
	{
		if (map_data->map[x][map_data->width - 1] != WALL)
			ft_perror("Invalid border");
		x++;
	}
}

void	icon_find(char c, char *icons)
{
	int	i;

	i = 0;
	while (icons[i])
	{
		if (icons[i] == c)
			return ;
		i++;
	}
	ft_perror("Invalid icon on map");
}

void	icon_count(t_map *map_data, char c, int x, int y)
{
	if (c == COLLECT)
		map_data->collect++;
	if (c == PLAYER)
	{
		map_data->pos_x = x;
		map_data->pos_y = y;
		map_data->n_player++;
	}
	if (c == EXIT)
		map_data->exit++;
}

void	icon_check(t_map *map_data)
{
	int	x;
	int	y;

	x = 0;
	while (map_data->map[x])
	{
		y = 0;
		while (map_data->map[x][y])
		{
			icon_find(map_data->map[x][y], "CPE10");
			icon_count(map_data, map_data->map[x][y], x, y);
			y++;
		}
		x++;
	}
	map_data->f_collect = map_data->collect;
	if (map_data->n_player != 1 || map_data->collect < 1 || map_data->exit != 1)
		ft_perror("Invalid icon amount");
}
