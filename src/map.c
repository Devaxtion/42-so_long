/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:32:48 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/21 14:12:38 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		is_map_valid(void)
{
	// can only be composed of 0, 1, C, E, P

	// Must contain 1 exit, 1 starting position
	// and atleast 1 collectible

	// Map must be rectangular

	// Map be surrounded by walls/1

	// Must there be a valid path

	// Other errors, error
}

char	**init_map(int argc, int **argv)
{
	char	*map_ptr;
	char	**map;
	int		i;

	if (argc != 2)
		cleanup_and_exit(0);

	// make sure it ends with .ber
	;

	// try to open it, if it doesnt exist, error
	map_ptr = fopen(argv[1], "r");
	if (!map_ptr)
		cleanup_and_exit(ERR_CANT_OPEN_FILE);
	
	// transform into an array
	i = 0;
	while (map[i] != NULL)
	{
		map[i] = get_next_line(map_ptr);
		i++;
	}
	

	// close file descriptor
	fclose(map_ptr);


	return (map);
}