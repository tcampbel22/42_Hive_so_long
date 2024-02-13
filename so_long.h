/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:42:29 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/13 16:41:31 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "lib/MLX42/include/MLX42/MLX42.h"
# include "libft/includes/libft.h"

# define WALL '1'
# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_map
{
	int		pos_x;
	int		pos_y;
	int		n_player;
	int		exit;
	int		collect;
	int		space;
	int		width;
	int		height;
	char	**map;
} t_map;


void	ft_perror(char *str);
void	init_layout(t_map *layout);
void	parse_map(char *map_file, t_map *layout);
void	map_check(t_map *layout);
void	shape_check(t_map *layout);
void	row_check(t_map *layout);
void	column_check(t_map *layout);
char	*append_line(char *line, char *map_str);
void	icon_check(t_map *layout);
void	icon_find(char c);
char	**copy_map(char **dup_map, t_map *layout);
void	ft_floodfill(char **map, t_map *layout, int pos_x, int pos_y);
void	valid_path(t_map *layout);
#endif
