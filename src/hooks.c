/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:05:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/27 11:40:44 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_data *data)
{
	ft_printf("Keycode received: %d\n", keycode);
	if (keycode == K_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		cleanup_and_exit(0, NULL);
	}
	if (keycode == K_A)
		data->square_x -= 50;
	if (keycode == K_D)
		data->square_x += 50;
	if (keycode == K_W)
		data->square_y -= 50;
	if (keycode == K_S)
		data->square_y += 50;
	return (0);
}

// int	resize_handler(int event, t_vars *vars)
// {
// 	if (event == 22 && vars)
// 		ft_printf("Window has been resized!\n");
// 	return (0);
// }

int	destroy_handler(t_data *data)
{
	ft_printf("Window closed by user. Exiting.\n");
	mlx_destroy_window(data->mlx, data->win);
	cleanup_and_exit(0, NULL);
	return (0);
}

// int	mouse_handler(int button, int x, int y, t_vars *vars)
// {
// 	ft_printf("Mouse Input received: %i, %i, %i\n", button, x, y);
// 	if (!vars)
// 		return (0);
// 	return (0);
// }

