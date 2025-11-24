/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:42:08 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/24 13:18:34 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	data.map = parse_map(&data, argc, argv);
	data.mlx = mlx_init();
	parse_components(&data);
	data.width = data.components.width * data.map.width;
	data.height = data.components.height * data.map.height;
	data.win = mlx_new_window(data.mlx, data.width, data.height, GAME_TITLE);
	mlx_hook(data.win, DESTROY_EVENT, NO_MASK, destroy_handler, &data);
	mlx_key_hook(data.win, key_handler, &data);
	mlx_loop_hook(data.mlx, draw_elements, &data);
	mlx_loop(data.mlx);
}
