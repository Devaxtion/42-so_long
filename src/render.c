/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:28:09 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/04 14:38:40 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_cell(t_data *data, char element, int x, int y)
{
	if (element == FLOOR)
		mlx_put_image_to_window(data->mlx, data->win,
			data->components.floor, x, y);
	if (element == WALL)
		mlx_put_image_to_window(data->mlx, data->win,
			data->components.wall, x, y);
	if (element == PLAYER)
		mlx_put_image_to_window(data->mlx, data->win,
			data->components.player, x, y);
	if (element == COLLECTIBLE)
		mlx_put_image_to_window(data->mlx, data->win,
			data->components.collectible, x, y);
	if (element == EXIT)
		mlx_put_image_to_window(data->mlx, data->win,
			data->components.exit, x, y);
}

int	draw_elements(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < data->map.height)
	{
		y = i * data->components.width;
		j = 0;
		while (j < data->map.width)
		{
			x = j * data->components.height;
			draw_cell(data, data->map.grid[i][j], x, y);
			j++;
		}
		i++;
	}
	return (0);
}
