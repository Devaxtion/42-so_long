/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:23:39 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/20 15:42:04 by leramos-         ###   ########.fr       */
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
