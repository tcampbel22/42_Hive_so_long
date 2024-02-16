/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/16 16:38:10 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) &&
		(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_up(game);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) &&
		(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_down(game);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) &&
		(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_right(game);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) &&
		(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_left(game);
}
