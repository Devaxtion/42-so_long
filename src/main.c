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

int	square_move(t_data *data)
{
	clear_buffer(&data->buffer, data->width, data->height, 0x000000);

	draw_square(&data->buffer, data->square_x, data->square_y, 20, 0x00FF00);

	mlx_put_image_to_window(data->mlx, data->win, data->buffer.img, 0, 0);

	// move square
	data->square_x++;
	if (data->square_x > data->width)
		data->square_x = 0;

	return (0);
}

// Your program must take a map description file with
// the extension .ber as a parameter
int	main(int argc, char **argv)
{
	t_data	data;

	init_map(argc, argv);

	// ✅ Set the resolution
	data.width = 800;
	data.height = 600;

	// ✅ Initialize the mlx + window
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.width, data.height, "Hello MLX!");

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
