/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:35 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/06 18:12:42 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shape_check(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]) - 1;
	ft_printf("\nWidth = %i\n", len);
	while (map[i])
		i++;
	ft_printf("Height = %i\n", i);
	if (len == i)
		return (0);
	return (1);
}

int	map_check()
{
	int		i;
	t_map	layout;
	if (!&shape_check)
		return (1);
	if (layout.n_player != 1 || layout.collect < 1 || layout.exit != 1)
		return (1);
	i = 0;
	return (0);
}

char	**free_str_1(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

void	ft_perror(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}
int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	*map_str;
	char	*map_file;
	char	**map;
	int		i;

	map_file = av[1];
	line = NULL;
	map_str = NULL;
	map = NULL;
	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_perror("Failed to open file or file does exist");
	if (ac != 2)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (!map_str)
		{
			map_str = ft_strdup("");
			if (!map_str)
			{
				ft_free(&map_str);
				return (0);
			}
		}
		else
			map_str = ft_strjoin_gnl(line, map_str);

	}
	map = ft_split(map_str, '\n');
	if (!map)
		ft_free(map);
	free(map_str);
	free_str_1(map);
}

