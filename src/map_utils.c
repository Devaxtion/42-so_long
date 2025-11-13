/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:27:29 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/04 14:36:44 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_map map, int i, int j, int mark)
{
	char	forbidden;

	forbidden = WALL;
	if (i < 0 || i >= map.height)
		return ;
	if (j < 0 || j >= map.width)
		return ;
	if (map.grid[i][j] == forbidden || map.grid[i][j] == mark)
		return ;
	map.grid[i][j] = mark;
	ft_flood_fill(map, i + 1, j, mark);
	ft_flood_fill(map, i - 1, j, mark);
	ft_flood_fill(map, i, j + 1, mark);
	ft_flood_fill(map, i, j - 1, mark);
}

static char	**clone_grid(char **src, int height)
{
	char	**dst;
	int		i;

	dst = (char **)malloc(sizeof(char *) * (height + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < height)
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst[i])
		{
			while (--i >= 0)
				free(dst[i]);
			free(dst);
			return (NULL);
		}
		i++;
	}
	dst[height] = NULL;
	return (dst);
}

t_map	clone_map(t_map src)
{
	t_map	dst;

	dst.height = src.height;
	dst.width = src.width;
	dst.collectibles = src.collectibles;
	dst.player = src.player;
	dst.grid = clone_grid(src.grid, src.height);
	return (dst);
}
