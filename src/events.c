/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:05:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/03 15:04:23 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_player(t_data *data, int keycode)
{
	int	x_new;
	int	y_new;

	x_new = data->map.player.row;
	y_new = data->map.player.col;
	if (keycode == K_A)
		x_new--;
	if (keycode == K_D)
		x_new++;
	if (keycode == K_W)
		y_new--;
	if (keycode == K_S)
		y_new++;
	
	if (data->map.grid[y_new][x_new] == WALL)
		return (0);
	
	if (data->map.grid[y_new][x_new] == COLLECTIBLE)
	{
		data->map.grid[data->map.player.col][data->map.player.row] = FLOOR;
		data->map.grid[y_new][x_new] = PLAYER;
		data->map.player.collected++;
	}
	
	if (data->map.grid[y_new][x_new] == EXIT)
	{
		if (data->map.player.collected < data->map.collectibles)
			return (0);
		data->map.grid[data->map.player.col][data->map.player.row] = FLOOR;
		return (2);
	}
	
	// if 0, just move
	if (data->map.grid[y_new][x_new] == FLOOR)
	{
		data->map.grid[data->map.player.col][data->map.player.row] = FLOOR;
		data->map.grid[y_new][x_new] = PLAYER;
	}

	// Update player location
	data->map.player.row = x_new;
	data->map.player.col = y_new;

	return (1);
}

int	key_handler(int keycode, t_data *data)
{
	int	code;

	code = 0;
	// ft_printf("Keycode received: %d\n", keycode);
	if (keycode == K_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		cleanup_and_exit(0, NULL);
	}
	if (keycode == K_A || keycode == K_D || keycode == K_W || keycode == K_S)
		code = move_player(data, keycode);
	if (code == 2)
		cleanup_and_exit(0, NULL);
	if (code == 1)
	{
		data->map.player.move_count += 1;
		ft_printf("Player moved | Count = %i\n", data->map.player.move_count);
	}
	return (0);
}

int	destroy_handler(t_data *data)
{
	ft_printf("Window closed by user. Exiting.\n");
	mlx_destroy_window(data->mlx, data->win);
	cleanup_and_exit(0, NULL);
	return (0);
}
