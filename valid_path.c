/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:32:01 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/13 11:40:05 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **dup_map, t_map *layout)
{
	int		i;

	i = 0;
	dup_map = ft_calloc(layout->height + 1, sizeof (char *));
	if (!dup_map)
	{
		ft_free_two(layout->map);
		ft_perror("Malloc Failure");
	}
	i = 0;
	while (layout->map[i])
	{
		dup_map[i] = ft_strdup(layout->map[i]);
		if (!dup_map[i])
		{
			ft_free_two(dup_map);
			ft_perror("Malloc Failure");
		}
		i++;
	}
	return (dup_map);
}

void	ft_floodfill(char **map, t_map *layout, int pos_x, int pos_y)
{
	if (map[pos_x][pos_y] == WALL || map[pos_x][pos_y] == 2)
		return ;
	if (map[pos_x][pos_y] == 'C')
		layout->collect--;
	if (map[pos_x][pos_y] == 'E')
		layout->exit--;
	map[pos_x][pos_y] = 2;
	ft_floodfill(map, layout, pos_x, pos_y + 1);
	ft_floodfill(map, layout, pos_x, pos_y - 1);
	ft_floodfill(map, layout, pos_x + 1, pos_y);
	ft_floodfill(map, layout, pos_x - 1, pos_y);
}

void	valid_path(t_map *layout)
{
	char **dup_map;

	dup_map = NULL;
	dup_map = copy_map(dup_map, layout);
	ft_floodfill(dup_map, layout, layout->pos_x, layout->pos_y);
	ft_free_two(dup_map);
	if (layout->collect != 0 || layout->exit != 0)
		ft_perror("No valid path");
}
