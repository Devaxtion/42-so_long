/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:37:08 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/30 14:19:51 by leramos-         ###   ########.fr       */
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
# define ERR_EMPTY_FILE 2
# define ERR_MALLOC_FAIL 3
# define ERR_INVALID_MAP 4
# define ERR_INVALID_EXTENSION 5

// Assets
# define FLOOR_FILE "./assets/floor.xpm"
# define WALL_FILE "./assets/wall.xpm"
# define PLAYER_FILE "./assets/player.xpm"
# define COLLECTIBLE_FILE "./assets/collectible.xpm"
# define EXIT_FILE "./assets/exit.xpm"

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
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}			t_assets;

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		player_x; // 1
	int		player_y; // 3
	int		collectible_count;
	int		collected_count;
	int		moves;
}			t_map;

typedef struct	s_data {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_img		buffer;
	t_assets	components;
	t_map		map;
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

// Map Validation
int		is_map_valid(t_map map);

// Map
t_map	parse_map(int argc, char **argv);

// Utils
void	buffered_pixel_put(t_img *img, int x, int y, int color);
void	clear_buffer(t_img *img, int width, int height, int color);
int		has_only_allowed_chars(char *str, char *chars);

// Forms
void	draw_square(t_img *img, int center_x, int center_y, int radius, int color);
void	draw_circle(t_img *img, int center_x, int center_y, int radius, int color);

// Render
int	game(t_data *data);

// Hooks
int	key_handler(int keycode, t_data *data);
// int	resize_handler(int event, t_vars *vars);
int	destroy_handler(t_data *data);
// int	mouse_handler(int button, int x, int y, t_vars *vars);

// Exit
void	cleanup_and_exit(int status_code, const char *error_msg);

#endif