/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:34:26 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/03 14:45:36 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Just checks if the Width is the same in all lines
static int	is_map_rectangular(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		// ft_printf("map.grid[%i] len = %i | map.width = %i\n", i, ft_strlen(map.grid[i]), map.width);
		if ((int)ft_strlen(map.grid[i]) != map.width)
			return (0);
		i++;
	}
	return (1);
}

static int	does_map_only_have_allowed_chars(t_map map)
{
	int	i;
	char allowed_chars[6];

	allowed_chars[0] = WALL;
	allowed_chars[1] = FLOOR;
	allowed_chars[2] = PLAYER;
	allowed_chars[3] = COLLECTIBLE;
	allowed_chars[4] = EXIT;
	allowed_chars[5] = '\0';
	i = 0;
	while (i < map.height)
	{
		if (!has_only_allowed_chars(map.grid[i], allowed_chars))
			return (0);
		i++;
	}
	return (1);
}

static int	are_map_elements_valid(t_map map)
{
	int	i;
	int	j;
	int exit_count;
	int	player_count;

	exit_count = 0;
	player_count = 0;
	i = 1;
	while (i < map.height - 1)
	{
		j = 0;
		while (j < map.width - 1)
		{
			if (map.grid[i][j] == EXIT)
				exit_count++;
			if (map.grid[i][j] == PLAYER)
				player_count++;
			j++;
		}
		i++;
	}
	if (exit_count != 1 || player_count != 1)
		return (0);
	if (map.collectibles < 1)
		return (0);
	return (1);
}

static int	is_map_surrounded_by_walls(t_map map)
{
	int	i;
	char allowed_chars[2];

	allowed_chars[0] = WALL;
	allowed_chars[1] = '\0';
	i = 0;
	while (i < map.height)
	{
		if (i == 0 || i == map.height - 1)
		{
			if (!has_only_allowed_chars(map.grid[i], allowed_chars))
				return (0);
		}
		else
		{
			if (map.grid[i][0] != WALL || map.grid[i][map.width - 1] != WALL)
				return (0);
		}
		i++;
	}
	return (1);
}

static void	ft_flood_fill(t_map map, int i, int j, int mark)
{
	char	forbidden;

	forbidden = WALL;
	if (i < 0 || i >= map.height)
		return ;
	if (j < 0 || j >= map.width)
		return ;
	if (map.grid[i][j] == forbidden || map.grid[i][j] == mark)
		return;
	map.grid[i][j] = mark;
	ft_flood_fill(map, i + 1, j, mark);
	ft_flood_fill(map, i - 1, j, mark);
	ft_flood_fill(map, i, j + 1, mark);
	ft_flood_fill(map, i, j - 1, mark);
}

static t_map	clone_map(t_map src)
{
	t_map	dst;
	int		i;

	dst.height = src.height;
	dst.width = src.width;
	dst.collectibles = src.collectibles;
	dst.player = src.player;
	dst.grid = (char **)malloc(sizeof(char *) * (dst.height + 1));
	if (!dst.grid)
		cleanup_and_exit(ERR_MALLOC_FAIL, "Failed to allocate map clone");
	i = 0;
	while (i < dst.height)
	{
		dst.grid[i] = ft_strdup(src.grid[i]);
		if (!dst.grid[i])
		{
			/* cleanup partially allocated clone then exit */
			while (--i >= 0)
				free(dst.grid[i]);
			free(dst.grid);
			cleanup_and_exit(ERR_MALLOC_FAIL, "Failed to allocate map clone");
		}
		i++;
	}
	dst.grid[dst.height] = NULL;
	return (dst);
}

static int	map_has_valid_path(t_map map)
{
	t_map	map_clone;
	int		i;
	int		j;
	char	mark;

	map_clone = clone_map(map);
	mark = '-';
	ft_flood_fill(map_clone, map_clone.player.col, map_clone.player.row, mark);
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.grid[i][j] == EXIT || map.grid[i][j] == COLLECTIBLE)
			{
				if (map_clone.grid[i][j] != mark)
					return (free_map(&map_clone), 0);
			}
			j++;
		}
		i++;
	}
	return (free_map(&map_clone), 1);
}

int	is_map_valid(t_map map)
{
	ft_printf("Validating map...\n");

	// Map must be rectangular
	if (!is_map_rectangular(map))
		return (0);
	ft_printf("- Map is rectangular\n");

	// Only must countain the correct chars
	if (!does_map_only_have_allowed_chars(map))
		return (0);
	ft_printf("- Map only contains chars from elements\n");

	// Must contain 1 exit, 1 starting position and atleast 1 collectible
	if (!are_map_elements_valid(map))
		return (0);
	ft_printf("- Map elements are valid\n");

	// Map be surrounded by walls
	if (!is_map_surrounded_by_walls(map))
		return (0);
	ft_printf("- Map is surrounded by walls\n");

	// Must there be a valid path
	if (!map_has_valid_path(map))
		return (0);
	ft_printf("- Map has a valid path\n");

	return (1);
}
