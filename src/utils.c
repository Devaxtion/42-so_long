/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:23:39 by leramos-          #+#    #+#             */
/*   Updated: 2025/11/04 14:39:37 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_only_allowed_chars(char *str, char *chars)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (str[i])
	{
		j = 0;
		found = 0;
		while (chars[j] && !found)
		{
			if (str[i] == chars[j])
				found = 1;
			j++;
		}
		if (!found)
			return (0);
		i++;
	}
	return (1);
}

void	trim_newline(char *str)
{
	int	last_char_index;

	if (!str)
		return ;
	last_char_index = ft_strlen(str) - 1;
	if (str[last_char_index] == '\n')
		str[last_char_index] = '\0';
}

int	is_valid_extension(char *filename, char *extension)
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

int	get_line_count(char *file_name)
{
	int		fd;
	char	*line;
	int		line_count;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line_count++;
		free(line);
	}
	close(fd);
	return (line_count);
}
