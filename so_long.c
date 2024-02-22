/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/22 12:13:39 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_perror(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	kill_mlx(t_map *game)
{
	if (game->map)
		ft_free_two(game->map);
//	if (game->images)
//		free(game->images);
	mlx_terminate(game->mlx);
	if (game)
		free(game);
}

void	name_check(char *map_file)
{
	char	*suffix;

	if (ft_strlen(map_file) < 5)
		ft_perror("Invalid file name");
	suffix = ft_strnstr(map_file, ".ber", ft_strlen(map_file));
	if (ft_strncmp(suffix, ".ber", ft_strlen(suffix)) != 0)
		ft_perror("Invalid file type");
}

int	main(int ac, char **av)
{
	t_map			*game;
	t_img			*images;

	if (ac != 2)
		ft_perror("Invalid arg amount");
	name_check(av[1]);
	game = parse_map(av[1]);
	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	game->mlx = mlx_init(game->width * PIX, game->height * PIX, "DINO", false);
	if (!game->mlx)
		ft_perror("MLX Failure");
	images = init_images(game);
	if (!images)
		ft_perror("Images failed to load");
	game->img = images;
	build_map(game);
	mlx_set_window_pos(game->mlx, 1000, 50);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_free_two(game->map);
	free(images);
	free(game);
	exit(EXIT_SUCCESS);
}
