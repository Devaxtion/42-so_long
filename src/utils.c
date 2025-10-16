/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:23:39 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/16 14:12:33 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calculate_offset(int x, int y, int line_length, int bits_per_pixel)
{
	return (y * line_length + x * (bits_per_pixel / 8));
}

void	buffered_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + calculate_offset(x, y, data->line_length, data->bits_per_pixel);
	*(unsigned int*)dst = color;
}


void	print_square(t_data *data, int center_x, int center_y, int radius, int color)
{
	int	x, y;
	int	left, right, top, bottom;

	// Pre-calculate boundaries once
	left = center_x - radius - 1;
	right = center_x + radius + 1;
	top = center_y - radius - 1;
	bottom = center_y + radius + 1;

	// Top line
	x = left;
	y = top;
	while (x <= right)
		buffered_pixel_put(data, x++, y, color);

	// Bottom line
	x = left;
	y = bottom;
	while (x <= right)
		buffered_pixel_put(data, x++, y, color);

	// Left line (excluding corners already drawn)
	x = left;
	y = top + 1;
	while (y < bottom)
		buffered_pixel_put(data, x, y++, color);

	// Right line (excluding corners already drawn)
	x = right;
	y = top + 1;
	while (y < bottom)
		buffered_pixel_put(data, x, y++, color);
}