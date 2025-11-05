/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:05:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/04 14:33:19 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_data *data, char target)
{
	if (target == WALL)
		return (0);
	if (target == EXIT && data->map.player.collected < data->map.collectibles)
		return (0);
	return (1);
}

static void	update_player_pos(t_data *data, char target, int row_new, int col_new)
{
	if (target == COLLECTIBLE)
			data->map.player.collected++;
	data->map.grid[data->map.player.col][data->map.player.row] = FLOOR;
	data->map.grid[col_new][row_new] = PLAYER;
	data->map.player.move_count += 1;
	data->map.player.row = row_new;
	data->map.player.col = col_new;
}

static int	move_player(t_data *data, int keycode)
{
	int		row_new;
	int		col_new;
	char	target;

	row_new = data->map.player.row;
	col_new = data->map.player.col;
	if (keycode == K_A)
		row_new--;
	else if (keycode == K_D)
		row_new++;
	else if (keycode == K_W)
		col_new--;
	else if (keycode == K_S)
		col_new++;
	else
		return (0);
	target = data->map.grid[col_new][row_new];
	if (!is_valid_move(data, target))
		return (0);
	update_player_pos(data, target, row_new, col_new);
	if (target == EXIT)
		return (2);
	if (target == FLOOR || target == COLLECTIBLE)
		return (1);
	return (0);
}

int	destroy_handler(t_data *data)
{
	ft_printf("Window closed by user. Exiting.\n");
	cleanup_and_exit(0, NULL, data);
	return (0);
}

int	key_handler(int keycode, t_data *data)
{
	int	code;

	if (keycode == K_ESC)
		destroy_handler(data);
	code = move_player(data, keycode);
	if (code == 1)
		ft_printf("Player moved -> Count = %i\n", data->map.player.move_count);
	else if (code == 2)
	{
		ft_printf("You won with %i moves!\n", data->map.player.move_count);
		cleanup_and_exit(0, NULL, data);
	}
	return (0);
}
