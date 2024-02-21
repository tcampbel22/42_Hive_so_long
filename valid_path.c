/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:32:01 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/21 15:39:51 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **dup_map, t_map *map_data)
{
	int		i;

	i = 0;
	dup_map = ft_calloc(map_data->height + 1, sizeof (char *));
	if (!dup_map)
	{
		ft_free_two(map_data->map);
		ft_perror("Malloc Failure");
	}
	i = 0;
	while (map_data->map[i])
	{
		dup_map[i] = ft_strdup(map_data->map[i]);
		if (!dup_map[i])
		{
			ft_free_two(dup_map);
			ft_perror("Malloc Failure");
		}
		i++;
	}
	return (dup_map);
}

void	ft_floodfill(char **map, t_map *map_data, int pos_x, int pos_y)
{
	if (map[pos_x][pos_y] == WALL || map[pos_x][pos_y] == 2)
		return ;
	if (map[pos_x][pos_y] == 'C')
		map_data->collect--;
	if (map[pos_x][pos_y] == 'E')
		map_data->exit--;
	map[pos_x][pos_y] = 2;
	ft_floodfill(map, map_data, pos_x, pos_y + 1);
	ft_floodfill(map, map_data, pos_x, pos_y - 1);
	ft_floodfill(map, map_data, pos_x + 1, pos_y);
	ft_floodfill(map, map_data, pos_x - 1, pos_y);
}

void	valid_path(t_map *map_data)
{
	char	**dup_map;

	dup_map = NULL;
	dup_map = copy_map(dup_map, map_data);
	ft_floodfill(dup_map, map_data, map_data->pos_x, map_data->pos_y);
	ft_free_two(dup_map);
	if (map_data->collect != 0 || map_data->exit != 0)
		ft_perror("No valid path");
}
