/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/22 15:43:35 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_image(t_map *game, int x, int y)
{
	if (game->map[y][x] == WALL)
		mlx_image_to_window(game->mlx, game->img->wall, x * PIX, y * PIX);
	if (game->map[y][x] == EXIT)
		mlx_image_to_window(game->mlx, game->img->lock_door, x * PIX, y * PIX);
	if (game->map[y][x] == EXIT)
	{
		mlx_image_to_window(game->mlx, game->img->open_door, x * PIX, y * PIX);
		game->img->open_door->instances->enabled = false;
	}
	if (game->map[y][x] == COLLECT)
		mlx_image_to_window(game->mlx, game->img->potion, x * PIX, y * PIX);
	if (game->map[y][x] == PLAYER)
		mlx_image_to_window(game->mlx, game->img->player, x * PIX, y * PIX);
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
			mlx_image_to_window(game->mlx, game->img->grass, x * PIX, y * PIX);
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
