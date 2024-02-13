/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:39:43 by tcampbel          #+#    #+#             */
/*   Updated: 2024/02/13 15:20:10 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*append_line(char *buffer, char *map_str)
{
	char	*temp;

	temp = ft_strjoin(map_str, buffer);
	free(map_str);
	return (temp);
}

void	line_check(char *map_str)
{
	if (map_str[0] == '\n')
		ft_perror("Empty line at start of map");
	else if (map_str[ft_strlen(map_str) - 2] == '\n')
		ft_perror("Empty line at end of map");
	else if (ft_strnstr(map_str, "\n\n", ft_strlen(map_str)))
		ft_perror("Empty line in map");
}

void	read_map(char *map_file, t_map *layout)
{
	int		fd;
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*map_str;

	map_str = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_perror("Failed to open file or file does not exist");
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!map_str)
		{
			if (!buffer[0])
				ft_perror("Map is empty");
			map_str = ft_strdup(buffer);
		}
		else if (map_str || bytes_read)
			map_str = append_line(buffer, map_str);
		if (!map_str)
		{
			ft_free(&map_str);
			close(fd);
			ft_perror("Malloc Failure");;
		}
	}
	line_check(map_str);
	layout->map = ft_split(map_str, '\n');
	ft_free(&map_str);
	close(fd);
}

void	parse_map(char *map_file, t_map *layout)
{
	int		i;

	i = 0;
	layout = malloc(sizeof(t_map));
	read_map(map_file, layout);
/*	while (layout->map[i])
	{
		ft_printf("%s\n", layout->map[i]);
		i++;
	}*/
	map_check(layout);
	ft_free_two(layout->map);
	free(layout);
}
