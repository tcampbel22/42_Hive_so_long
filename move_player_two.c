/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:17:06 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/22 15:46:19 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_map *game)
{
	game->img->lock_door->instances->enabled = false;
	game->img->open_door->instances->enabled = true;
}

void	end_game(t_map *game)
{
	if (game->pos_y == game->img->open_door->instances[0].x / PIX
		&& game->pos_x == game->img->open_door->instances[0].y / PIX
		&& game->img->open_door->instances->enabled == true)
	{
		ft_printf("Great Success!");
		mlx_close_window(game->mlx);
	}
}

void	collect_find(t_map *game)
{
	int	i;

	i = 0;
	while (i <= game->f_collect)
	{
		if (game->pos_y == game->img->potion->instances[i].x / PIX
			&& game->pos_x == game->img->potion->instances[i].y / PIX)
		{
			if (game->img->potion->instances[i].enabled == true)
				game->collect++;
			game->img->potion->instances[i].enabled = false;
		}
		i++;
	}
	if (game->f_collect == game->collect)
		open_exit(game);
}
