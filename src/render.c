/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:28:09 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/30 14:12:36 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	frame_counter(void)
// {
// 	static int	frame = 0;

// 	frame++;
// 	if (frame % 100000 == 0)
// 		ft_printf("Frame %d\n", frame);
// 	return (0);
// }

// int	square_move(t_data *data)
// {
// 	clear_buffer(&data->buffer, data->width, data->height, 0x000000);

// 	draw_square(&data->buffer, data->square_x, data->square_y, 20, 0x00FF00);

// 	mlx_put_image_to_window(data->mlx, data->win, data->buffer.img, 0, 0);

// 	// move square
// 	data->square_x++;
// 	if (data->square_x > data->width)
// 		data->square_x = 0;

// 	return (0);
// }

// static void	fill_background(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < data->height)
// 	{
// 		x = 0;
// 		while (x < data->width)
// 		{
// 			mlx_put_image_to_window(data->mlx, data->win, data->components.floor, x, y);
// 			x += data->components.width;
// 		}
// 		y += data->components.height;
// 	}
// }

static void	draw_elements(t_data *data)
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
			// draw background
			mlx_put_image_to_window(data->mlx, data->win, data->components.floor, x, y);
			// draw elements
			if (data->map.grid[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->components.wall, x, y);
			if (data->map.grid[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->components.player, x, y);
			if (data->map.grid[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->components.collectible, x, y);
			if (data->map.grid[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->components.exit, x, y);
			j++;
		}
		i++;
	}
}

int	game(t_data *data)
{
	clear_buffer(&data->buffer, data->width, data->height, 0x000000);
	// fill_background(data);
	// draw_walls(data); with data.map.grid info
	// draw_exit(data); with data.map.grid info
	// draw_collectibles ...
	// draw_player ...

	draw_elements(data); // with data.map.grid info

	// draw player
	
	return (0);
}
