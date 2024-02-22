/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/22 12:30:54 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*init_images(t_map *game)
{
	t_img	*png;

	png = malloc(sizeof(t_img));
	if (!png)
		ft_perror("Malloc Failure");
	png = load_grass(game, png);
	png = load_wall(game, png);
	png = load_exit(game, png);
	png = load_open_exit(game, png);
	png = load_collectable(game, png);
	png = load_player(game, png);
	return (png);
}

t_img	*load_grass(t_map *game, t_img *png)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./assets/grass.png");
	if (!grass)
	{
		kill_mlx(game);
		ft_perror("Texture failed to load");
	}
	png->grass = mlx_texture_to_image(game->mlx, grass);
	if (!png->grass)
	{
		kill_mlx(game);
		ft_perror("Image failed to load");
	}
	mlx_resize_image(png->grass, PIX, PIX);
	mlx_delete_texture(grass);
	return (png);
}

t_img	*load_wall(t_map *game, t_img *png)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("./assets/wall.png");
	if (!wall)
	{
		kill_mlx(game);
		ft_perror("Texture failed to load");
	}
	png->wall = mlx_texture_to_image(game->mlx, wall);
	if (!png->wall)
	{
		kill_mlx(game);
		ft_perror("Image failed to load");
	}
		mlx_resize_image(png->wall, PIX, PIX);
	mlx_delete_texture(wall);
	return (png);
}

t_img	*load_exit(t_map *game, t_img *png)
{
	mlx_texture_t	*door;

	door = mlx_load_png("./assets/door_closed.png");
	if (!door)
	{
		kill_mlx(game);
		ft_perror("Texture failed to load");
	}
	png->lock_door = mlx_texture_to_image(game->mlx, door);
	if (!png->lock_door)
	{
		kill_mlx(game);
		ft_perror("Image failed to load");
	}
	mlx_resize_image(png->lock_door, PIX, PIX);
	mlx_delete_texture(door);
	return (png);
}
