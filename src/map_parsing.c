/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:32:48 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/04 14:36:17 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**init_grid(char *file_name, int map_height)
{
	char	**map;
	int		fd;
	char	*line;
	int		i;

	map = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		trim_newline(line);
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

static void	scan_map_elements(t_map *map)
{
	int	i;
	int	j;

	map->collectibles = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == PLAYER)
			{
				map->player.col = i;
				map->player.row = j;
			}
			if (map->grid[i][j] == COLLECTIBLE)
				map->collectibles++;
			j++;
		}
		i++;
	}
}

t_map	parse_map(t_data *data, int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		cleanup_and_exit(ERR_INVALID_ARG_COUNT, "Invalid argument count", data);
	if (!is_valid_extension(argv[1], "ber"))
		cleanup_and_exit(ERR_INVALID_EXT, "File extension isn't ber", data);
	map.height = get_line_count(argv[1]);
	if (map.height == -1)
		cleanup_and_exit(ERR_CANT_READ_FILE, "Couldn't read file", data);
	if (map.height == 0)
		cleanup_and_exit(ERR_EMPTY_FILE, "Map is empty", data);
	map.grid = init_grid(argv[1], map.height);
	if (!map.grid)
		cleanup_and_exit(ERR_CANT_INIT_MAP, "Couldn't initialize map", data);
	map.width = ft_strlen(map.grid[0]);
	scan_map_elements(&map);
	if (!is_map_valid(map))
		cleanup_and_exit(ERR_INVALID_MAP, "Map is invalid", data);
	map.player.collected = 0;
	map.player.move_count = 0;
	return (map);
}
