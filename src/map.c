/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:32:48 by leramos-          #+#    #+#             */
/*   Updated: 2025/10/27 12:58:18 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void strtrim_newline(char *s)
{
    int len;

    if (!s)
        return;
    
    len = ft_strlen(s);
    // Check if the last character is a newline
    if (len > 0 && s[len - 1] == '\n')
    {
        // Replace the newline with a null terminator
        s[len - 1] = '\0';
    }
}

static int	is_valid_extension(char *filename, char *extension)
{
	int		filename_len;
	int		extension_len;
	char	*extension_idx;

	extension_len = ft_strlen(extension);

	filename_len = ft_strlen(filename);
	if (filename_len < extension_len + 2)
		return (0);

	extension_idx = ft_strnstr(filename, extension, filename_len);

	if (extension_idx == NULL)
		return (0);
	if ((extension_idx - filename) == (filename_len - (extension_len + 1)))
		return (0);
	return (1);
}

static int	get_line_count(char *file_name)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		cleanup_and_exit(ERR_CANT_OPEN_FILE, "Couldn't open the file");
	line_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		line_count++;
		free(line);
	}
	close(fd);
	return (line_count);
}

static char	**init_map(char *file_name, int map_height)
{
	char	**map;
	int		fd;
	char 	*line;
	int		i;

	map = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (!map)
		cleanup_and_exit(ERR_MALLOC_FAIL, "Failed to allocate map");
	
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		cleanup_and_exit(ERR_CANT_OPEN_FILE, "Couldn't open the file");

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		strtrim_newline(line);
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**parse_map(int argc, char **argv)
{
	char	**map;
	int		map_height;

	if (argc != 2)
		cleanup_and_exit(0, NULL);

	if (!is_valid_extension(argv[1], "ber"))
		cleanup_and_exit(ERR_INVALID_EXTENSION, "Map file extension isn't .ber");

	map_height = get_line_count(argv[1]);
	if (map_height == 0)
		cleanup_and_exit(ERR_EMPTY_FILE, "Map file is empty");
	
	map = init_map(argv[1], map_height);

	if (!is_map_valid(map, map_height))
		cleanup_and_exit(ERR_INVALID_MAP, "Map is invalid");
	
	return (map);
}
