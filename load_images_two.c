/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:38:57 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/22 17:35:12 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_open_exit(t_map *game, t_img *png)
{
	mlx_texture_t	*open_door;

	open_door = mlx_load_png("./assets/door_fullyopen.png");
	if (!open_door)
	{
		kill_mlx(game);
		ft_perror("Texture failed to load");
	}
	png->open_door = mlx_texture_to_image(game->mlx, open_door);
	if (!png->open_door)
	{
		kill_mlx(game);
		ft_perror("Image failed to load");
	}
	mlx_resize_image(png->open_door, PIX, PIX);
	mlx_delete_texture(open_door);
	return (png);
}

t_img	*load_collectable(t_map *game, t_img *png)
{
	mlx_texture_t	*potion;

	potion = mlx_load_png("./assets/potion.png");
	if (!potion)
	{
		kill_mlx(game);
		ft_perror("Texture failed to load");
	}
	png->potion = mlx_texture_to_image(game->mlx, potion);
	if (!png->potion)
	{
		kill_mlx(game);
		ft_perror("Image failed to load");
	}
	mlx_resize_image(png->potion, PIX, PIX);
	mlx_delete_texture(potion);
	return (png);
}

t_img	*load_player(t_map *game, t_img *png)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./assets/dino_right_3.png");
	if (!player)
	{
		kill_mlx(game);
		ft_perror("Texture failed to load");
	}
	png->player = mlx_texture_to_image(game->mlx, player);
	if (!png->player)
	{
		kill_mlx(game);
		ft_perror("Image failed to load");
	}
	mlx_resize_image(png->player, PIX, PIX);
	mlx_delete_texture(player);
	return (png);
}
