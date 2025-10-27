/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:34:26 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/27 12:58:38 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// str = "ALALALA"
// chars = "ALZ"
static int	has_only_allowed_chars(char *str, char *chars)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (str[i])
	{
		j = 0;
		found = 0;
		while (chars[j] && !found)
		{
			// ft_printf("str[%i] = %c | chars[%i] = %c\n", i, str[i], j, chars[j]);
			if (str[i] == chars[j])
				found = 1;
			j++;
		}
		if (!found)
			return (0);
		i++;
	}
	return (1);
}

int	are_map_elements_valid(char **map, int map_height, int map_weight)
{
	int	i;
	int	j;
	int exit_count;
	int	start_count;
	int	collectible_count;

	exit_count = 0;
	start_count = 0;
	collectible_count = 0;
	i = 1;
	while (i < map_height - 1)
	{
		j = 0;
		while (j < map_weight - 1)
		{
			if (map[i][j] == 'E')
				exit_count++;
			if (map[i][j] == 'P')
				start_count++;
			if (map[i][j] =='C')
				collectible_count++;
			j++;
		}
		i++;
	}
	ft_printf("e = %i, s = %i, c = %i\n", exit_count, start_count, collectible_count);
	if (exit_count != 1 || start_count != 1 || collectible_count == 0)
		return (0);
	return (1);
}

static int	is_map_rectangular(char **map, int map_height, int map_weight)
{
	int	i;

	i = 1;
	while (i < map_height)
	{
		// ft_printf("map[%i] len = %i | map_weight = %i\n", i, ft_strlen(map[i]), map_weight);
		if ((int)ft_strlen(map[i]) != map_weight)
			return (0);
		i++;
	}
	return (1);
}

int	is_map_valid(char **map, int map_height)
{
	int	i;
	int map_weight;

	map_weight = ft_strlen(map[0]);

	// Map must be rectangular
	if (!is_map_rectangular(map, map_height, map_weight))
		return (0);
	
	ft_printf("Map is rectangular\n");

	// Only must countain the chars 01CEP
	i = 0;
	while (i < map_height)
	{
		if (!has_only_allowed_chars(map[i], "01CEP"))
			return (0);
		i++;
	}

	ft_printf("Map only contains chars 01CEP\n");

	// Must contain 1 exit, 1 starting position and atleast 1 collectible
	if (!are_map_elements_valid(map, map_height, map_weight))
		return (0);

	ft_printf("Map only contains 1 exit, 1 start position and 1c\n");

	// Map be surrounded by walls/1

	// Must there be a valid path

	// Other errors, error
	if (map)
		return (1);
	return (0);
}