/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/12 15:25:12 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	shape_check(t_map *layout)
{
	int	x;
	int	y;

	x = 1;
	layout->width = ft_strlen(layout->map[0]);
	while (layout->map[x])
	{
		y = 0;
		while (layout->map[x][y])
			y++;
		if (y != layout->width)
			ft_perror("Invalid map shape");
		x++;
	}
	layout->height = x;
}

void	map_check(t_map *layout)
{
	init_layout(layout);
	shape_check(layout);
	row_check(layout);
	column_check(layout);
	icon_check(layout);
	valid_path(layout);
}

void	init_layout(t_map *layout)
{

	layout->pos_x = 0;
	layout->pos_y = 0;
	layout->n_player = 0;
	layout->exit = 0;
	layout->collect = 0;
	layout->space = 0;
	layout->width = 0;
	layout->height = 0;
}

void	ft_perror(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

void	name_check(char *map_file)
{
	char	*suffix;

	suffix = ft_strnstr(map_file, ".ber", ft_strlen(map_file));
	if (ft_strncmp(suffix, ".ber", ft_strlen(suffix)) != 0)
		ft_perror("Invalid file type");
}

int	main(int ac, char **av)
{
	char	*map_file;
	if (ac != 2)
		ft_perror("Invalid arg amount");
	if (ft_strlen(av[1]) < 5)
		ft_perror("Invalid file name");
	map_file = av[1];
	name_check(map_file);
	parse_map(map_file);
	exit(1);
}

