/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:37:08 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/16 13:54:38 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// open, close, read, write
# include <unistd.h>

// malloc, free, exit
# include <stdlib.h>

// perror
# include <stdio.h>

// strerror
# include <string.h>

// INT_MAX
# include <limits.h>

// MinilibX
# include <mlx.h>

// Libft
# include "libft.h"
# include "ft_printf.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

// Utils

int		calculate_offset(int x, int y, int line_length, int bits_per_pixel);
void	buffered_pixel_put(t_data *data, int x, int y, int color);
void	print_square(t_data *data, int center_x, int center_y, int radius, int color);

// Color Utils

int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

#endif