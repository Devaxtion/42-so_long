/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:05:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/20 15:44:52 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_vars *vars)
{
	ft_printf("Keycode received: %d\n", keycode);
	if (keycode == K_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
    if (keycode == K_A)
	{
		vars->circle_x -= 50;
		exit(0);
	}
    if (keycode == K_D)
	{
		vars->circle_x += 50;
		exit(0);
	}
	return (0);
}

int	resize_handler(int event, t_vars *vars)
{
	if (event == 22 && vars)
		ft_printf("Window has been resized!\n");
	return (0);
}

int	destroy_handler(t_vars *vars)
{
	ft_printf("Window closed by user. Exiting.\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_vars *vars)
{
	ft_printf("Mouse Input received: %i, %i, %i\n", button, x, y);
	if (!vars)
		return (0);
	return (0);
}


int render_next_frame(t_vars *data)
{
    // 1. CLEAR the entire screen (black background)
    for (int y = 0; y < 1080; y++)
    {
        for (int x = 0; x < 1920; x++)
        {
            buffered_pixel_put(dataimg, x, y, 0x00000000); // Black
        }
    }
    
    // 2. DRAW the circle at current position
    draw_circle(data->img, data->circle_x, data->circle_y, 50, 0x00FF0000); // Red circle
    
    // 3. DISPLAY the new frame
    mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
    
    return (0);
}
