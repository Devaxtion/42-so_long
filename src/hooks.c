/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:05:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/17 12:05:44 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(vars->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int	resize_handler(int event, t_vars *vars)
{
	if (event == 22)
		printf("Window has been resized!\n");
	return (0);
}

int	destroy_handler(int event, t_vars *vars)
{
	ft_printf("Window closed by user. Exiting.\n")
	mlx_destroy_window(vars->mlx, mlx->win);
	exit(0);
	return (0);
}
