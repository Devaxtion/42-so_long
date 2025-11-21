/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:34:26 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/04 14:37:11 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_map_rect_and_allowed_chars(t_map map)
{
	int		i;
	char	allowed_chars[6];

	allowed_chars[0] = WALL;
	allowed_chars[1] = FLOOR;
	allowed_chars[2] = PLAYER;
	allowed_chars[3] = COLLECTIBLE;
	allowed_chars[4] = EXIT;
	allowed_chars[5] = '\0';
	i = 0;
	while (i < map.height)
	{
		if ((int)ft_strlen(map.grid[i]) != map.width)
			return (0);
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
	int	exit_count;
	int	player_count;

	exit_count = 0;
	player_count = 0;
	i = 1;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.grid[i][j] == EXIT)
				exit_count++;
			if (map.grid[i][j] == PLAYER)
				player_count++;
			j++;
		}
		i++;
	}
	if (exit_count != 1 || player_count != 1 || map.collectibles < 1)
		return (0);
	return (1);
}

static int	is_map_surrounded_by_walls(t_map map)
{
	int		i;
	char	allowed_chars[2];

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

static int	map_has_valid_path(t_map map)
{
	t_map	map_clone;
	int		i;
	int		j;

	map_clone = clone_map(map);
	if (!map_clone.grid)
		return (0);
	ft_flood_fill(map_clone, map_clone.player.y, map_clone.player.x, '-');
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if ((map.grid[i][j] == EXIT || map.grid[i][j] == COLLECTIBLE)
				&& map_clone.grid[i][j] != '-')
				return (free_map(&map_clone), 0);
			j++;
		}
		i++;
	}
	return (free_map(&map_clone), 1);
}

int	is_map_valid(t_map map)
{
	if (!is_map_rect_and_allowed_chars(map))
		return (0);
	if (!are_map_elements_valid(map))
		return (0);
	if (!is_map_surrounded_by_walls(map))
		return (0);
	if (!map_has_valid_path(map))
		return (0);
	return (1);
}
