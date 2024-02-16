/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:52:38 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/16 15:35:20 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	move_up(t_map *game)
{
	int	x;
	int	y;

	y = game->pos_y;
	x = game->pos_x;
	if (game->map[x - 1][y] == WALL)
		return ;
	game->img->dino->instances->y -= PIXELS;
	game->pos_x -= 1;
	ft_printf("Up\n");
}

void	move_down(t_map *game)
{
	int	x;
	int	y;

	y = game->pos_y;
	x = game->pos_x;
	if (game->map[x + 1][y] == WALL)
		return ;
	game->img->dino->instances->y += PIXELS;
	game->pos_x += 1;
	ft_printf("Down\n");
}

void	move_left(t_map *game)
{
	int	x;
	int	y;

	y = game->pos_y;
	x = game->pos_x;
	if (game->map[x][y - 1] == WALL)
		return ;
	game->img->dino->instances->x -= PIXELS;
	game->pos_y -= 1;
	ft_printf("Left\n");
}

void	move_right(t_map *game)
{
	int	x;
	int	y;

	y = game->pos_y;
	x = game->pos_x;
	if (game->map[x][y + 1] == WALL)
		return ;
	game->img->dino->instances->x += PIXELS;
	game->pos_y += 1;
	ft_printf("Right\n");
}
