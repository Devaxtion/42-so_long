/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:42:08 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/04 14:32:50 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_components(t_data *data)
{
	data->components.floor = mlx_xpm_file_to_image(data->mlx, FLOOR_FILE, &(data->components.width), &(data->components.height));
	data->components.wall = mlx_xpm_file_to_image(data->mlx, WALL_FILE, &(data->components.width), &(data->components.height));
	data->components.player = mlx_xpm_file_to_image(data->mlx, PLAYER_FILE, &(data->components.width), &(data->components.height));
	data->components.collectible = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE_FILE, &(data->components.width), &(data->components.height));
	data->components.exit = mlx_xpm_file_to_image(data->mlx, EXIT_FILE, &(data->components.width), &(data->components.height));
	if (data->components.floor == NULL || data->components.wall == NULL
		|| data->components.player == NULL || data->components.collectible == NULL
		|| data->components.exit == NULL)
		cleanup_and_exit(ERR_CANT_READ_IMG, "Image reading has failed", data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	// ✅ Parse map
	data.map = parse_map(&data, argc, argv);

	// ✅ Initialize the mlx
	data.mlx = mlx_init();

	// ✅ Parse all the components from .xpm into pointers
	parse_components(&data);

	// ✅ Set the resolution and create the window
	data.width = data.components.width * data.map.width;
	data.height = data.components.height * data.map.height;
	data.win = mlx_new_window(data.mlx, data.width, data.height, "So Long");

	// ✅ Create image buffer
	data.buffer.img = mlx_new_image(data.mlx, data.width, data.height);
	data.buffer.addr = mlx_get_data_addr(
			data.buffer.img,
			&data.buffer.bits_per_pixel,
			&data.buffer.line_length,
			&data.buffer.endian
	);

	// ✅ Hooks
	mlx_key_hook(data.win, key_handler, &data);
	mlx_hook(data.win, DESTROY_EVENT, NO_MASK, destroy_handler, &data);

	mlx_loop_hook(data.mlx, draw_elements, &data);
	mlx_loop(data.mlx);
}
