/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:42:29 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/22 12:27:05 by tcampbel         ###   ########.fr       */
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
# define COLLECT 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define PIX 64

typedef struct s_img
{
	mlx_image_t	*grass;
	mlx_image_t	*wall;
	mlx_image_t	*lock_door;
	mlx_image_t	*open_door;
	mlx_image_t	*potion;
	mlx_image_t	*player;
}	t_img;

typedef struct s_map
{
	int			pos_x;
	int			pos_y;
	int			n_player;
	int			exit;
	int			collect;
	int			f_collect;
	int			steps;
	int			width;
	int			height;
	t_img		*img;
	mlx_t		*mlx;
	char		**map;
}	t_map;

void	ft_perror(char *str);
t_map	*init_layout(char **map);
t_map	*parse_map(char *map_file);
void	map_check(t_map *map_data);
void	shape_check(t_map *map_data);
void	row_check(t_map *map_data);
void	column_check(t_map *map_data);
char	*append_line(char *line, char *map_str);
void	icon_check(t_map *map_data);
void	icon_find(char c, char *icons);
char	**copy_map(char **dup_map, t_map *map_data);
void	ft_floodfill(char **map, t_map *map_data, int pos_x, int pos_y);
void	valid_path(t_map *map_data);
char	*create_string(char *map_str, char *buffer, int bytes_read, int fd);

t_img	*init_images(t_map *game);
t_img	*load_grass(t_map *game, t_img *png);
t_img	*load_wall(t_map *game, t_img *png);
t_img	*load_exit(t_map *game, t_img *png);
t_img	*load_open_exit(t_map *game, t_img *png);
t_img	*load_collectable(t_map *game, t_img *png);
t_img	*load_player(t_map *game, t_img *png);
void	build_map(t_map *game);
void	add_background(t_map *game);
void	add_image(t_map *game, int x, int y);

void	my_key_hook(mlx_key_data_t keydata, void *param);
void	move_up(t_map *game);
void	move_down(t_map *game);
void	move_left(t_map *game);
void	move_right(t_map *game);
void	collect_find(t_map *game);
void	end_game(t_map *game);
void	open_exit(t_map *game);

void	kill_mlx(t_map *game);

#endif
