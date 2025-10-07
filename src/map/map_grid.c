/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:05:25 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 18:22:11 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_grid_strings(t_map *map)
{
	size_t		i;
	t_string	*ptr;

	i = 0;
	while (i < map->grid.size)
	{
		ptr = (t_string *)ft_vec_get(&map->grid, i);
		if (ptr)
			ft_tstr_free(ptr);
		i = i + 1;
	}
	ft_vec_free(&map->grid);
}

int	push_map_line(t_map *map, char *cstr_line)
{
	t_string	copy;

	copy = ft_tstr_from_cstr(cstr_line);
	ft_vec_push(&map->grid, &copy, 1);
	return (1);
}

static int	check_no_content_after_map(int fd)
{
	t_string	line;
	size_t		i;

	line = get_next_line(fd);
	while (line.len > 0)
	{
		i = 0;
		while (i < line.len && line.data[i])
		{
			if (line.data[i] != '\n' && line.data[i] != '\0')
			{
				ft_tstr_free(&line);
				return (0);
			}
			i++;
		}
		ft_tstr_free(&line);
		line = get_next_line(fd);
	}
	ft_tstr_free(&line);
	return (1);
}

/*
** read_map_lines_loop:
**   Reads all following map lines from file descriptor fd.
**   - If it finds an invalid line, clears the grid and returns 0.
**   - If the line is valid, adds it to the grid.
**   - Terminates upon finding an empty line or non-map line.
**   - Verifies there is no content after the map.
*/

int	read_map_lines_loop(int fd, t_map *map)
{
	t_string	line;

	line = get_next_line(fd);
	while (line.len > 0)
	{
		if (is_map_line(line.data))
		{
			if (!is_valid_line(line.data))
				return (ft_putstr_fd("Error\nInvalid character in map\n", 2),
					ft_tstr_free(&line), clear_grid_strings(map), 0);
			push_map_line(map, line.data);
			ft_tstr_free(&line);
		}
		else
		{
			ft_tstr_free(&line);
			if (!check_no_content_after_map(fd))
				return (ft_putstr_fd("Error\nContent found after map\n", 2),
					clear_grid_strings(map), 0);
			break ;
		}
		line = get_next_line(fd);
	}
	ft_tstr_free(&line);
	return (1);
}

bool	parse_map_grid(int fd, t_map *map, char *first_line)
{
	map->grid = ft_vec(10, sizeof(t_string));
	if (!push_map_line(map, first_line))
		return (false);
	if (!read_map_lines_loop(fd, map))
		return (false);
	map->height = map->grid.size;
	if (map->height < 3)
	{
		ft_putstr_fd("Error\nMap too small (minimum 3 rows)\n", 2);
		clear_grid_strings(map);
		return (false);
	}
	return (is_map_surrounded(map));
}
