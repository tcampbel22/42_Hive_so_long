/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/19 12:03:17 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	add_image(t_map *game, size_t x, size_t y)
{
	if (game->map[y][x] == WALL)
		mlx_image_to_window(game->mlx, game->img->wall, x * PIXELS , y * PIXELS);
	if (game->map[y][x] == EXIT)
		mlx_image_to_window(game->mlx, game->img->locked_door, x * PIXELS , y * PIXELS);
	if (game->map[y][x] == COLLECT)
		mlx_image_to_window(game->mlx, game->img->potion, x * PIXELS , y * PIXELS);
	if (game->map[y][x] == PLAYER)
		mlx_image_to_window(game->mlx, game->img->right[0], x * PIXELS , y * PIXELS);
}


void	add_background(t_map *game)
{
	size_t	x;
	size_t	y;
	
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, game->img->grass, x * PIXELS , y * PIXELS);
		x++;
		}
		y++;
	}
}


void	build_map(t_map *game)
{
	size_t	x;
	size_t	y;
	
	y = 0;
	add_background(game);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			add_image(game, x, y);
			x++;
		}
		y++;
	}
}

