/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:42:29 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/06 17:52:47 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "libft/includes/libft.h"

typedef struct s_player
{
	int	x;
	int	y;
} player;

typedef struct s_map
{
	player	player_pos;
	int		n_player;
	int		exit;
	int		collect;
	int		space;
	int		width;
	int		height;
} t_map;

#endif
