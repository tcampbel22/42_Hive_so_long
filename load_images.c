/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/21 15:49:12 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*init_images(mlx_t *mlx)
{
	t_img	*png;

	png = malloc(sizeof(t_img));
	if (!png)
		ft_perror("Malloc Failure");
	png = load_grass(mlx, png);
	png = load_wall(mlx, png);
	png = load_exit(mlx, png);
	png = load_open_exit(mlx, png);
	png = load_collectable(mlx, png);
	png = load_player(mlx, png);
	return (png);
}

t_img	*load_grass(mlx_t *mlx, t_img *png)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./assets/grass.png");
	if (!grass)
		ft_perror("Texture failed to load");
	png->grass = mlx_texture_to_image(mlx, grass);
	if (!png->grass)
		ft_perror("Image failed to load");
	mlx_resize_image(png->grass, PIX, PIX);
	mlx_delete_texture(grass);
	return (png);
}

t_img	*load_wall(mlx_t *mlx, t_img *png)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./assets/wall.png");
	if (!wall)
		ft_perror("Texture failed to load");
	png->wall = mlx_texture_to_image(mlx, wall);
	if (!png->wall)
		ft_perror("Image failed to load");
	mlx_resize_image(png->wall, PIX, PIX);
	mlx_delete_texture(wall);
	return (png);
}

t_img	*load_exit(mlx_t *mlx, t_img *png)
{
	mlx_texture_t	*door;

	door = mlx_load_png("./assets/door_closed.png");
	if (!door)
		ft_perror("Texture failed to load");
	png->lock_door = mlx_texture_to_image(mlx, door);
	if (!png->lock_door)
		ft_perror("Image failed to load");
	mlx_resize_image(png->lock_door, PIX, PIX);
	mlx_delete_texture(door);
	return (png);
}
