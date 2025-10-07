/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:41:32 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 13:52:20 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	has_cub_ext(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strcmp(filename + (len - 4), ".cub") != 0)
		return (0);
	return (1);
}

/*
** process_until_map:
**   Reads 'fd' until it finds the beginning of the map.
**   - If the line is an element (NO/SO/EA/WE/F/C), calls parse_elements().
**   - If the line looks like a map, validates and delegates to parse_map_grid().
*/

static int	process_until_map(int fd, t_map *map, t_game *game)
{
	t_string	line;

	line = get_next_line(fd);
	while (line.len > 0)
	{
		if (line.data[0] != '\0' && line.data[0] != '\n'
			&& !is_map_line(line.data))
		{
			if (!parse_elements(line.data, map, game))
				return (ft_tstr_free(&line), 0);
		}
		else if (is_map_line(line.data))
		{
			if (!is_valid_line(line.data))
				return (ft_putstr_fd("Error\nInvalid character\n", 2),
					ft_tstr_free(&line), 0);
			if (!parse_map_grid(fd, map, line.data))
				return (ft_tstr_free(&line), 0);
			return (ft_tstr_free(&line), 1);
		}
		(ft_tstr_free(&line), line = get_next_line(fd));
	}
	ft_putstr_fd("Error\nEmpty or invalid file\n", 2);
	return (ft_tstr_free(&line), 0);
}

/*
** parse_map_file:
**   Entry point for parsing the .cub file:
**   - Verifies extension.
**   - Opens file and processes header + map.
**   - Checks that all required elements and player exist.
**   - Validates that textures loaded correctly.
*/

bool	parse_map_file(char *filename, t_map *map, t_game *game)
{
	int	fd;
	int	ok;

	if (!has_cub_ext(filename))
		return (ft_putstr_fd("Error\nFile must have .cub extension\n", 2),
			false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nCould not open file\n", 2), false);
	ok = process_until_map(fd, map, game);
	close(fd);
	get_next_line(-1);
	if (!ok)
		return (false);
	if (!all_elements_present(map))
		return (false);
	if (!find_player(map))
		return (false);
	if (!validate_textures(map))
		return (false);
	return (true);
}
