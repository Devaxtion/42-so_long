/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:42:08 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/04 14:32:50 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*load_xpm_img(t_data *data, char *file)
{
	void	*component;
	int		width;
	int		height;

	component = mlx_xpm_file_to_image(data->mlx, file, &width, &height);
	if (component == NULL)
		cleanup_and_exit(ERR_CANT_READ_IMG, "Image reading has failed", data);
	data->components.width = width;
	data->components.height = height;
	return (component);
}

void	parse_components(t_data *data)
{
	data->components.floor = load_xpm_img(data, FLOOR_FILE);
	data->components.wall = load_xpm_img(data, WALL_FILE);
	data->components.player = load_xpm_img(data, PLAYER_FILE);
	data->components.collectible = load_xpm_img(data, COLLECTIBLE_FILE);
	data->components.exit = load_xpm_img(data, EXIT_FILE);
}
