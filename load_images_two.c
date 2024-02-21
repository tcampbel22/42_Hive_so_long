/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:38:57 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/21 15:50:02 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*load_open_exit(mlx_t *mlx, t_img *png)
{
	mlx_texture_t	*open_door;

	open_door = mlx_load_png("./assets/door_fullyopen.png");
	if (!open_door)
	{
		ft_perror("Texture failed to load");
	}
	png->open_door = mlx_texture_to_image(mlx, open_door);
	if (!png->open_door)
		ft_perror("Image failed to load");
	mlx_resize_image(png->open_door, PIX, PIX);
	mlx_delete_texture(open_door);
	return (png);
}

t_img	*load_collectable(mlx_t *mlx, t_img *png)
{
	mlx_texture_t	*potion;

	potion = mlx_load_png("./assets/potion.png");
	if (!potion)
		ft_perror("Texture failed to load");
	png->potion = mlx_texture_to_image(mlx, potion);
	if (!png->potion)
		ft_perror("Image failed to load");
	mlx_resize_image(png->potion, PIX, PIX);
	mlx_delete_texture(potion);
	return (png);
}

t_img	*load_player(mlx_t *mlx, t_img *png)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./assets/dino_right_3.png");
	if (!player)
		ft_perror("Texture failed to load");
	png->player = mlx_texture_to_image(mlx, player);
	if (!png->player)
		ft_perror("Image failed to load");
	mlx_resize_image(png->player, PIX, PIX);
	mlx_delete_texture(player);
	return (png);
}
