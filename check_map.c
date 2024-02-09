/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:34:56 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/09 18:33:27 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	row_check(t_map *layout)
{
	int	y;

	y = 0;
	while (layout->map[0][y])
	{
		if (layout->map[0][y] != WALL)
			ft_perror("Invalid border");
		y++;
	}
	y = 0;
	while (layout->map[layout->height - 1][y])
	{
		if (layout->map[layout->height - 1][y] != WALL)
			ft_perror("Invalid border");
		y++;
	}
}

void	column_check(t_map *layout)
{
	int	x;

	x = 0;
	while (layout->map[x])
	{
		if (layout->map[x][0] != WALL)
			ft_perror("Invalid border");
		x++;
	}
	x = 0;
	while (layout->map[x])
	{
		if (layout->map[x][layout->width - 1] != WALL)
			ft_perror("Invalid border");
		x++;
	}
}

void	icon_find(char c)
{
	char	icons[6] = "CPE10";
	int	i;

	i = 0;
	while (icons[i])
	{
		if (icons[i] == c)
			return ;
		i++;
	}
	ft_perror("Invalid icon on map");
}


void	icon_count(t_map *layout, char c)
{
	if (c == 'C')
		layout->collect++;
	if (c == 'P')
		layout->n_player++;
	if (c == 'E')
		layout->exit++;
}

void	icon_check(t_map *layout)
{
	int	x;
	int	y;

	x = 0;
	layout->collect = 0;
	layout->n_player = 0;
	layout->exit = 0;
	while (layout->map[x])
	{
		y = 0;
		while (layout->map[x][y])
		{
			icon_find(layout->map[x][y]);
			icon_count(layout, layout->map[x][y]);
			y++;
		}
		x++;
	}
}
