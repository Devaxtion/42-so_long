/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:05:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/30 14:41:51 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(t_data *data, int keycode)
{
	int	x_new;
	int	y_new;

	x_new = data->map.player_x;
	y_new = data->map.player_y;
	if (keycode == K_A)
		x_new--;
	if (keycode == K_D)
		x_new++;
	if (keycode == K_W)
		y_new--;
	if (keycode == K_S)
		y_new++;
	
	if (data->map.grid[y_new][x_new] == '1')
		return (0);
	
	if (data->map.grid[y_new][x_new] == 'C')
	{
		data->map.grid[data->map.player_y][data->map.player_x] = '0';
		data->map.grid[y_new][x_new] = 'P';
		data->map.collected_count++;
	}
	
	if (data->map.grid[y_new][x_new] == 'E')
	{
		if (data->map.collected_count < data->map.collectible_count)
			return (0);
		data->map.grid[data->map.player_y][data->map.player_x] = '0';
		return (2);
	}
	
	// if 0, just move
	if (data->map.grid[y_new][x_new] == '0')
	{
		data->map.grid[data->map.player_y][data->map.player_x] = '0';
		data->map.grid[y_new][x_new] = 'P';
	}

	// Update player location
	data->map.player_x = x_new;
	data->map.player_y = y_new;

	return (1);
}

int	key_handler(int keycode, t_data *data)
{
	int	code;

	ft_printf("Keycode received: %d\n", keycode);
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
		data->map.moves += 1;
		ft_printf("Player moved | Count = %i\n", data->map.moves);
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
