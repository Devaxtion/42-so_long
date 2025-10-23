/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:37:08 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/21 13:57:09 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// open, close, read, write
# include <unistd.h>

// malloc, free, exit
# include <stdlib.h>

// perror + strerror
# include <stdio.h>
# include <string.h>

// INT_MAX, Math, gettimeofday
# include <limits.h>
# include <math.h>
# include <sys/time.h>

// MinilibX + Libft
# include <mlx.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

// Errors
# define ERR_CANT_OPEN_FILE 1

// Assets
# define ASSET_RES 32
# define FLOOR_FILE "./assets/floor.xpm"
# define WALL_FILE "./assets/wall.xpm"
# define PLAYER_FILE "./assets/player.xpm"
# define COLLECTIBLE_FILE "./assets/collectible.xpm"

// Structs

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_assets
{
	int		width;
	int		height;
	void	*floor;
	// void	*wall;
	// void	*player;
	// void	*collectible;
}			t_assets;

typedef struct	s_data {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_img		buffer;
	int			square_x;
	int			square_y;
	t_assets	components;
}				t_data;

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
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100

// Utils
void	buffered_pixel_put(t_img *img, int x, int y, int color);
void	clear_buffer(t_img *img, int width, int height, int color);
// // Colors
// int	add_shade(double distance, int color);
// int	get_opposite(int color);

// Forms
void	draw_square(t_img *img, int center_x, int center_y, int radius, int color);
void	draw_circle(t_img *img, int center_x, int center_y, int radius, int color);

// // Color Utils
// int	create_trgb(int t, int r, int g, int b);
// int	get_t(int trgb);
// int	get_r(int trgb);
// int	get_g(int trgb);
// int	get_b(int trgb);

// Hooks
int	key_handler(int keycode, t_data *data);
// int	resize_handler(int event, t_vars *vars);
int	destroy_handler(t_data *data);
// int	mouse_handler(int button, int x, int y, t_vars *vars);

// Exit
void	cleanup_and_exit(int status_code);

#endif