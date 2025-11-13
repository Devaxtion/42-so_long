/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:03:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/04 14:33:41 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

static void	cleanup_mlx(t_data *data)
{
	if (!(data->mlx))
		return ;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->components.floor)
		mlx_destroy_image(data->mlx, data->components.floor);
	if (data->components.wall)
		mlx_destroy_image(data->mlx, data->components.wall);
	if (data->components.player)
		mlx_destroy_image(data->mlx, data->components.player);
	if (data->components.collectible)
		mlx_destroy_image(data->mlx, data->components.collectible);
	if (data->components.exit)
		mlx_destroy_image(data->mlx, data->components.exit);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->mlx = NULL;
}

void	cleanup_and_exit(int status_code, const char *error_msg, t_data *data)
{
	free_map(&data->map);
	cleanup_mlx(data);
	if (status_code != 0)
	{
		ft_printf("Error\n");
		if (error_msg)
			ft_printf("%s\n", error_msg);
	}
	exit(status_code);
}
