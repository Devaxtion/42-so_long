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

static int	calculate_offset(int x, int y, int line_length, int bits_per_pixel)
{
	return (y * line_length + x * (bits_per_pixel / 8));
}

static void	buffered_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + calculate_offset(x, y, img->line_length, img->bits_per_pixel);
	*(unsigned int *)dst = color;
}

void	clear_buffer(t_img *img, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			buffered_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_cell(t_data *data, char element, int x, int y)
{
	if (element == FLOOR)
		mlx_put_image_to_window(data->mlx, data->win, data->components.floor, x, y);
	if (element == WALL)
		mlx_put_image_to_window(data->mlx, data->win, data->components.wall, x, y);
	if (element == PLAYER)
		mlx_put_image_to_window(data->mlx, data->win, data->components.player, x, y);
	if (element == COLLECTIBLE)
		mlx_put_image_to_window(data->mlx, data->win, data->components.collectible, x, y);
	if (element == EXIT)
		mlx_put_image_to_window(data->mlx, data->win, data->components.exit, x, y);
}

int	draw_elements(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	clear_buffer(&data->buffer, data->width, data->height, 0x000000);
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
