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
