/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:42:08 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/30 14:12:22 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_components(t_data *data)
{
	data->components.floor = mlx_xpm_file_to_image(data->mlx, FLOOR_FILE, &(data->components.width), &(data->components.height));
	data->components.wall = mlx_xpm_file_to_image(data->mlx, WALL_FILE, &(data->components.width), &(data->components.height));
	data->components.player = mlx_xpm_file_to_image(data->mlx, PLAYER_FILE, &(data->components.width), &(data->components.height));
	data->components.collectible = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE_FILE, &(data->components.width), &(data->components.height));
	data->components.exit = mlx_xpm_file_to_image(data->mlx, EXIT_FILE, &(data->components.width), &(data->components.height));
}

// Your program must take a map description file with
// the extension .ber as a parameter
int	main(int argc, char **argv)
{
	t_data	data;

	// ✅ Parse map
	data.map = parse_map(argc, argv);
	if (!data.map.grid)
		cleanup_and_exit(ERR_INVALID_MAP, "Map is invalid");
	ft_printf("Parsed map\n");

	// ✅ Initialize the mlx
	data.mlx = mlx_init();
	ft_printf("Initialized the MLX\n");

	// ✅ Parse all the components from .xpm into pointers
	parse_components(&data);
	ft_printf("Parsed the components\n");

	// ✅ Set the resolution and create the window
	data.width = data.components.width * data.map.width;
	data.height = data.components.height * data.map.height;
	data.win = mlx_new_window(data.mlx, data.width, data.height, "Baza");
	ft_printf("Created the window of %ix%i\n", data.width, data.height);

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
	//mlx_hook(data.win, CONFIG_REQ_EVENT, STRUCT_NOTIFY_MASK, resize_handler, &data);
	mlx_hook(data.win, DESTROY_EVENT, NO_MASK, destroy_handler, &data);

	mlx_loop_hook(data.mlx, game, &data);
	mlx_loop(data.mlx);
}
