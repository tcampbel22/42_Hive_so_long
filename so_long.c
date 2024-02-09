/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/09 18:43:47 by tcampbel         ###   ########.fr       */
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

int	map_check(t_map *layout)
{
	shape_check(layout);
	row_check(layout);
	column_check(layout);
	icon_check(layout);
	if (layout->n_player != 1 || layout->collect < 0 || layout->exit != 1)
		ft_perror("Invalid icon amount");
	return (0);
}
/*
void	init_layout(t_map *layout)
{
//	ft_printf("Check1");
	layout->n_player = 0;
	layout->exit = 0;
	layout->collect = 0;
	layout->space = 0;
	layout->width = 0;
	layout->height = 0;
	layout->map = NULL;
}*/

void	ft_perror(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

int	main(int ac, char **av)
{
	char	*map_file;

	if (ac != 2)
		ft_perror("Invalid arg amount");
	map_file = av[1];
	parse_map(map_file);
	exit(1);
}

