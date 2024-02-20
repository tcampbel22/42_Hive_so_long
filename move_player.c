/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:52:38 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/20 16:12:20 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_map *game)
{
	game->img->locked_door->instances->enabled = false;
	game->img->open_door->instances->enabled = true;
}

void	collect_find(t_map *game)
{
	int	i;
	int	c;

	i = 0;
	c = game->f_collect;
	ft_printf("%i\n", c);
	while (i <= game->f_collect)
	{
		if (game->pos_y == game->img->potion->instances[i].x/PIXELS
			&& game->pos_x == game->img->potion->instances[i].y/PIXELS)
			{
				game->img->potion->instances[i].enabled = false;
				c--;
			}
		i++;
	}
	ft_printf("%c\n", i);
	if (c == 0)
		open_exit(game);
}

void	move_up(t_map *game)
{
	int	x;
	int	y;

	y = game->pos_y;
	x = game->pos_x;
	if (game->map[x - 1][y] == WALL)
		return ;
	game->img->right[0]->instances[0].y -= PIXELS;
	ft_printf("Steps: %i\n", game->steps++);
	game->pos_x -= 1;
	collect_find(game);
}

void	move_down(t_map *game)
{
	int	x;
	int	y;

	y = game->pos_y;
	x = game->pos_x;
	if (game->map[x + 1][y] == WALL)
		return ;
	game->img->right[0]->instances[0].y += PIXELS;
	ft_printf("Steps: %i\n", game->steps++);
	game->pos_x += 1;
	collect_find(game);
}

void	move_left(t_map *game)
{
	int	x;
	int	y;

	y = game->pos_y;
	x = game->pos_x;
	if (game->map[x][y - 1] == WALL)
		return ;
	game->img->right[0]->instances->x -= PIXELS;
	ft_printf("Steps: %i\n", game->steps++);
	game->pos_y -= 1;
	collect_find(game);
}

void	move_right(t_map *game)
{
	int	x;
	int	y;

	y = game->pos_y;
	x = game->pos_x;
	if (game->map[x][y + 1] == WALL)
		return ;
	game->img->right[0]->instances->x += PIXELS;
	ft_printf("Steps: %i\n", game->steps++);
	game->pos_y += 1;
	collect_find(game);
}

