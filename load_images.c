/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/13 17:33:06 by tcampbel         ###   ########.fr       */
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
	png = load_collectable(mlx, png);
	png = load_player(mlx, png);
	return (png);
}

t_img	*load_grass(mlx_t *mlx, t_img *png)
{
	mlx_texture_t	*grass;

	if (!(grass = mlx_load_png("./assets/grass.png")))
		ft_perror("Texture failed to load");
	if (!(png->grass = mlx_texture_to_image(mlx, grass)))
		ft_perror("Image failed to load");
	mlx_resize_image(png->grass, PIXELS, PIXELS);
	mlx_delete_texture(grass);
	return (png);
}

t_img	*load_wall(mlx_t *mlx, t_img *png)
{
	mlx_texture_t	*wall;

	if (!(wall = mlx_load_png("./assets/wall.png")))
		ft_perror("Texture failed to load");
	if (!(png->wall = mlx_texture_to_image(mlx, wall)))
		ft_perror("Image failed to load");
	mlx_resize_image(png->wall, PIXELS, PIXELS);
	mlx_delete_texture(wall);
	return (png);
}

t_img	*load_exit(mlx_t *mlx, t_img *png)
{
	mlx_texture_t	*door;

	if (!(door = mlx_load_png("./assets/door_closed.png")))
		ft_perror("Texture failed to load");
	if (!(png->locked_door = mlx_texture_to_image(mlx, door)))
		ft_perror("Image failed to load");
	mlx_resize_image(png->locked_door, PIXELS, PIXELS);
	mlx_delete_texture(door);
	return (png);
}

t_img	*load_collectable(mlx_t *mlx, t_img *png)
{
	mlx_texture_t	*potion;

	if (!(potion = mlx_load_png("./assets/potion.png")))
		ft_perror("Texture failed to load");
	if (!(png->potion = mlx_texture_to_image(mlx, potion)))
		ft_perror("Image failed to load");
	mlx_resize_image(png->potion, PIXELS, PIXELS);
	mlx_delete_texture(potion);
	return (png);
}

t_img	*load_player(mlx_t *mlx, t_img *png)
{
	mlx_texture_t	*player;

	if (!(player = mlx_load_png("./assets/dino_left.png")))
		ft_perror("Texture failed to load");
	if (!(png->dino = mlx_texture_to_image(mlx, player)))
		ft_perror("Image failed to load");
	mlx_resize_image(png->dino, PIXELS + 10, PIXELS);
	mlx_delete_texture(player);
	return (png);
}
