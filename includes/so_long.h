/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:37:08 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/20 15:43:46 by leramos-         ###   ########.fr       */
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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		frame_count;
	t_data	img;
	int		circle_x;
	int		circle_y;
}			t_vars;

// Events
# define DESTROY_EVENT 17
# define K_PRESS_EVENT 2
# define CONFIG_REQ_EVENT 22

// Masks
# define NO_MASK 0L
# define K_PRESS_MASK (1L << 0)
# define STRUCT_NOTIFY_MASK (1L << 17)

// Key Values
# define K_ESC 65307
# define K_A 10
# define K_D 20

// Utils
int		calculate_offset(int x, int y, int line_length, int bits_per_pixel);
void	buffered_pixel_put(t_data *data, int x, int y, int color);

// Colors
int	add_shade(double distance, int color);
int	get_opposite(int color);

// Forms
void	draw_square(t_data *data, int center_x, int center_y, int radius, int color);
void	draw_circle(t_data *data, int center_x, int center_y, int radius, int color);

// Color Utils
int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

// Hooks
int	key_handler(int keycode, t_vars *vars);
int	resize_handler(int event, t_vars *vars);
int	destroy_handler(t_vars *vars);
int	mouse_handler(int button, int x, int y, t_vars *vars);

int render_next_frame(t_vars *vars);

#endif