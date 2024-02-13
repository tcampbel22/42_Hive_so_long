/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/13 17:33:06 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_perror(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(1);
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
	char			*map_file;
	t_map			*layout;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*grass;

	if (ac != 2)
		ft_perror("Invalid arg amount");
	layout = NULL;
	map_file = av[1];
	name_check(map_file);
	parse_map(map_file, layout);
	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!mlx)
		ft_perror("MLX Failure");
	grass = mlx_load_png("./assets/grass.png");
	img = mlx_texture_to_image(mlx, grass);
	if (!img)
		ft_perror("Image generation failed");
/*	int32_t x = 0;
	int32_t y = 0;
	while (layout->map[x][y])
	{
		y = 0;
		while (layout->map[x][y])
		{
			if (layout->map[x][y] == WALL)
				mlx_image_to_window(mlx, img, x, y);
			y++;
		}
		x++;
	}*/
	mlx_image_to_window(mlx, img, 1, 0);
	mlx_set_window_pos(mlx, 1000, 50);
	mlx_loop(mlx);
	mlx_terminate(mlx);
//	free(mlx);
//	free(img);
//	free(grass);
	exit(1);
}

