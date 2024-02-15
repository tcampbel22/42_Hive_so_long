/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/13 17:33:06 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	add_image(t_map *game, size_t x, size_t y)
{
	if (game->map[x][y] == WALL)
		mlx_image_to_window(game->mlx, game->img->wall, x * PIXELS , y * PIXELS);
	if (game->map[x][y] == EXIT)
		mlx_image_to_window(game->mlx, game->img->locked_door, x * PIXELS , y * PIXELS);
	if (game->map[x][y] == COLLECT)
		mlx_image_to_window(game->mlx, game->img->potion, x * PIXELS , y * PIXELS);
	if (game->map[x][y] == PLAYER)
		mlx_image_to_window(game->mlx, game->img->dino, x * PIXELS , y * PIXELS);

}


void	add_background(t_map *game)
{
	size_t	x;
	size_t	y;
	
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			mlx_image_to_window(game->mlx, game->img->grass, x * PIXELS , y * PIXELS);
			y++;
		}
		x++;
	}
}


void	build_map(t_map *game)
{
	size_t	x;
	size_t	y;
	
	x = 0;
	add_background(game);
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			add_image(game, x, y);
			y++;
		}
		x++;
	}
}

