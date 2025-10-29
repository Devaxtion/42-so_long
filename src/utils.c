/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:23:39 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/21 12:19:56 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	calculate_offset(int x, int y, int line_length, int bits_per_pixel)
{
	return (y * line_length + x * (bits_per_pixel / 8));
}

void	buffered_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + calculate_offset(x, y, img->line_length, img->bits_per_pixel);
	*(unsigned int*)dst = color;
}

void	clear_buffer(t_img *img, int width, int height, int color)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
			buffered_pixel_put(img, x, y, color);
	}
}

int	has_only_allowed_chars(char *str, char *chars)
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

// void	dfs(char **grid, int grid_height, int grid_width, int i, int j, char old, char new)
// {
// 	if (i < 0 || i >= grid_height)
// 		return ;
// 	if (j < 0 || j >= grid_width)
// 		return ;
// 	if (grid[i][j] != old)
// 		return;
// 	grid[i][j] = new;
// 	ft_dfs(grid, grid_height, grid_width, i + 1, j, old, new);
// 	ft_dfs(grid, grid_height, grid_width, i - 1, j, old, new);
// 	ft_dfs(grid, grid_height, grid_width, i, j + 1, old, new);
// 	ft_dfs(grid, grid_height, grid_width, i, j - 1, old, new);
// }

// void	flood_fill(char **grid, int grid_height, int grid_width, int i, int j, char new)
// {
// 	char	old;

// 	old = grid[i][j];
// 	if (old == new)
// 		return ;
// 	dfs(grid, grid_height, grid_width, i, j, old, new);
// }

// t_map clone_map(t_map src)
// {
// 	t_map dst;
// 	int	i;

// 	dst = malloc(sizeof(t_map));

// 	dst.height = src.height;
// 	dst.widht = src.widht;
// 	dst.grid = (char **)malloc(sizeof(char *) * (dst.height + 1));
// 	i = 0;
// 	while (i < dst.height)
// 	{
// 		ft_strcpy(dst.grid[i], src.grid[i]);
// 		i++;
// 	}
// 	return (dst);
// }
