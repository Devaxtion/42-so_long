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
	void	*component;

	if (element == FLOOR)
		component = data->components.floor;
	if (element == WALL)
		component = data->components.wall;
	if (element == PLAYER)
		component = data->components.player;
	if (element == COLLECTIBLE)
		component = data->components.collectible;
	if (element == EXIT)
		component = data->components.exit;
	mlx_put_image_to_window(data->mlx, data->win, component, x, y);
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
		y = i * data->components.height;
		j = 0;
		while (j < data->map.width)
		{
			x = j * data->components.width;
			draw_cell(data, data->map.grid[i][j], x, y);
			j++;
		}
		i++;
	}
	return (0);
}
