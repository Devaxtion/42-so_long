/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:37:49 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/20 15:42:38 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_square(t_data *data, int center_x, int center_y, int radius, int color)
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

// Simple circle drawing function
void draw_circle(t_data *data, int center_x, int center_y, int radius, int color)
{
    for (int y = center_y - radius; y <= center_y + radius; y++)
    {
        for (int x = center_x - radius; x <= center_x + radius; x++)
        {
            // Check if pixel is within circle using distance formula
            int dx = x - center_x;
            int dy = y - center_y;
            if (dx * dx + dy * dy <= radius * radius)
            {
                buffered_pixel_put(data, x, y, color);
            }
        }
    }
}
