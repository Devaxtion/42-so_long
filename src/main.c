/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:42:08 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/16 14:10:32 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_vars	vars;
	t_data	img;
	int		x;
	int		y;

	x = 1920;
	y = 1080;
	vars.mlx = mlx_init();
	
	vars.win = mlx_new_window(vars.mlx, x, y, "Hello world!");
	img.img = mlx_new_image(vars.mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// buffered_pixel_put(&img, 5, 5, 0x00FF0000);
	print_square(&img, 500, 500, 200, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	mlx_hook(vars.win, 2, 1L<<0, key_handler, &vars);
	mlx_hook(vars.win, 22, 1L<<17, resize_handler, &vars);
	mlx_hook(vars.win, 17, 0, destroy_handler, &vars);
	mlx_loop(vars.mlx);
	
	return (0);
}
