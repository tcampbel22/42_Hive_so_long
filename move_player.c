/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:52:38 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/21 15:33:56 by tcampbel         ###   ########.fr       */
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
	game->img->player->instances[0].y -= PIX;
	ft_printf("Steps: %i\n", game->steps++);
	game->pos_x -= 1;
	collect_find(game);
	end_game(game);
}

void	move_down(t_map *game)
{
	int	x;
	int	y;

	y = game->pos_y;
	x = game->pos_x;
	if (game->map[x + 1][y] == WALL)
		return ;
	game->img->player->instances[0].y += PIX;
	ft_printf("Steps: %i\n", game->steps++);
	game->pos_x += 1;
	collect_find(game);
	end_game(game);
}

void	move_left(t_map *game)
{
	int	x;
	int	y;

	y = game->pos_y;
	x = game->pos_x;
	if (game->map[x][y - 1] == WALL)
		return ;
	game->img->player->instances->x -= PIX;
	ft_printf("Steps: %i\n", game->steps++);
	game->pos_y -= 1;
	collect_find(game);
	end_game(game);
}

void	move_right(t_map *game)
{
	int	x;
	int	y;

	y = game->pos_y;
	x = game->pos_x;
	if (game->map[x][y + 1] == WALL)
		return ;
	game->img->player->instances->x += PIX;
	ft_printf("Steps: %i\n", game->steps++);
	game->pos_y += 1;
	collect_find(game);
	end_game(game);
}
