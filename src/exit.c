/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:03:44 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/03 15:00:03 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	free_stack(t_stack *stack)
// {
// 	if (stack)
// 	{
// 		if (stack->data)
// 			free(stack->data);
// 		free(stack);
// 	}
// }

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

void	cleanup_and_exit(int status_code, const char *error_msg)
{
	// free_map(&data->map);
	if (status_code != 0)
	{
		ft_printf("Error\n");
		if (error_msg)
			ft_printf("%s\n", error_msg);
	}
	exit(status_code);
}
