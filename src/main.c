/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:42:08 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/21 13:37:55 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	frame_counter(void)
{
	static int	frame = 0;

	frame++;
	if (frame % 100000 == 0)
		ft_printf("Frame %d\n", frame);
	return (0);
}

void	fill_background(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->components.floor, x, y);
			x += data->components.width;
		}
		y += data->components.height;
	}
}

int	square_move(t_data *data)
{
	clear_buffer(&data->buffer, data->width, data->height, 0x000000);

	draw_square(&data->buffer, data->square_x, data->square_y, 20, 0x00FF00);

	fill_background(data);
	mlx_put_image_to_window(data->mlx, data->win, data->buffer.img, 0, 0);
	

	// move square
	data->square_x++;
	if (data->square_x > data->width)
		data->square_x = 0;

	return (0);
}

void	parse_components(t_data *data)
{
	data->components.floor = mlx_xpm_file_to_image(data->mlx, FLOOR_FILE, &(data->components.width), &(data->components.height));
	// data->components->wall = mlx_xpm_file_to_image(data->mlx, WALL_FILE, data->components->width, data->components->height);
	// data->components->player = mlx_xpm_file_to_image(data->mlx, PLAYER_FILE, data->components->width, data->components->height);
	// data->components->collectible = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE_FILE, data->components->width, data->components->height);
}

// Your program must take a map description file with
// the extension .ber as a parameter
int	main(void)
{
	t_data	data;

	// map = parse_map(data);

	// ✅ Initialize the mlx
	data.mlx = mlx_init();
	ft_printf("Initialized the MLX\n");

	// Parse all the components from .xpm into pointers
	parse_components(&data);
	ft_printf("Parsed the components\n");

	// ✅ Set the resolution and create the window
	data.width = data.components.width * 13;
	data.height = data.components.height * 13;
	data.win = mlx_new_window(data.mlx, data.width, data.height, "Hello MLX!");
	ft_printf("Created the window of %ix%i\n", data.width, data.height);

	// ✅ Create image buffer
	data.buffer.img = mlx_new_image(data.mlx, data.width, data.height);
	data.buffer.addr = mlx_get_data_addr(
		data.buffer.img,
		&data.buffer.bits_per_pixel,
		&data.buffer.line_length,
		&data.buffer.endian
	);

	// ✅ Define the initial square location
	data.square_x = data.width / 2;
	data.square_y = data.height / 2;

	// ✅ Hooks
	mlx_key_hook(data.win, key_handler, &data);
	//mlx_hook(data.win, CONFIG_REQ_EVENT, STRUCT_NOTIFY_MASK, resize_handler, &data);
	mlx_hook(data.win, DESTROY_EVENT, NO_MASK, destroy_handler, &data);

	mlx_loop_hook(data.mlx, square_move, &data);
	mlx_loop(data.mlx);
}
