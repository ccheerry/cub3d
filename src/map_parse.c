/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:41:32 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/15 17:02:28 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_map_line(char *line)
{
	int		i;
	bool	has_map_char;

	if (!line || line[0] == '\0')
		return (false);
	i = 0;
	has_map_char = false;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '0' || line[i] == '1'
			|| line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W' || line[i] == ' ')
		{
			if (line[i] != ' ')
				has_map_char = true;
		}
		else
			return (false);
		i++;
	}
	return (has_map_char);
}

static bool	is_map_surrounded(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == '0' || map->grid[y][x] == 'N'
				|| map->grid[y][x] == 'S' || map->grid[y][x] == 'E'
				|| map->grid[y][x] == 'W')
			{
				if (y == 0 || y == map->height - 1
					|| x == 0 || x == (int)ft_strlen(map->grid[y]) - 1)
					return (false);
				if (map->grid[y - 1][x] == ' ' || map->grid[y + 1][x] == ' '
					|| map->grid[y][x - 1] == ' ' || map->grid[y][x + 1] == ' ')
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

static bool	parse_map_grid(int fd, t_map *map, char *first_line)
{
	t_string	line;
	t_vec		lines;
	size_t		i;
	char		*line_copy;
	char		*ptr;

	lines = ft_vec(10, sizeof(char *));
	line_copy = ft_strdup(first_line);
	ft_vec_push(&lines, &line_copy, 1);
	line = get_next_line(fd);
	while (line.len > 0)
	{
		if (is_map_line(line.data))
		{
			if (!is_valid_line(line.data))
			{
				ft_tstr_free(&line);
				i = -1;
				while (++i < lines.size)
				{
					ptr = *((char **)ft_vec_get(&lines, i));
					ft_free((void **)&ptr);
				}
				return (ft_vec_free(&lines), false);
			}
			line_copy = ft_strdup(line.data);
			ft_vec_push(&lines, &line_copy, 1);
			ft_tstr_free(&line);
		}
		else
		{
			ft_tstr_free(&line);
			break ;
		}
		line = get_next_line(fd);
	}
	map->height = lines.size;
	if (map->height < 3) // ask but i assume to be surrounded it should have at least 3 rows
		return (ft_vec_free(&lines), false);
	map->grid = ft_calloc(map->height + 1, sizeof(char *));
	i = 0;
	while ((int)i < map->height)
	{
		map->grid[i] = *((char **)ft_vec_get(&lines, i));
		i++;
	}
	return (ft_vec_free(&lines), is_map_surrounded(map));
}

static bool	find_player(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == 'N' || map->grid[y][x] == 'S'
				|| map->grid[y][x] == 'E' || map->grid[y][x] == 'W')
			{
				if (map->player.orientation != 0)
					return (false);
				map->player.x = (float)x;
				map->player.y = (float)y;
				map->player.orientation = map->grid[y][x];
				if (map->grid[y][x] == 'N')
					map->player.angle = 0;
				else if (map->grid[y][x] == 'S')
					map->player.angle = 180;
				else if (map->grid[y][x] == 'E')
					map->player.angle = 90;
				else if (map->grid[y][x] == 'W')
					map->player.angle = 270;
			}
			x++;
		}
		if (x > map->width)
			map->width = x;
		y++;
	}
	return (map->player.orientation != 0);
}

static bool	all_elements_present(t_map *map)
{
	return (map->textures.north && map->textures.south
		&& map->textures.east && map->textures.west);
}

bool	parse_map_file(char *filename, t_map *map, t_game *game)
{
	int			fd;
	t_string	line;
	bool		map_started;

	if (ft_strcmp(filename + ft_strlen(filename) - 4, ".cub") != 0)
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	map_started = false;
	line = get_next_line(fd);
	while (line.len > 0 && !map_started)
	{
		if (line.data[0] != '\0' && line.data[0] != '\n' && !is_map_line(line.data))
		{
			if (!parse_elements(line.data, map, game))
				return (ft_tstr_free(&line), close(fd), false);
		}
		else if (is_map_line(line.data))
		{
			map_started = true;
			if (!is_valid_line(line.data))
				return (ft_tstr_free(&line), close(fd), false);
			if (!parse_map_grid(fd, map, line.data))
				return (ft_tstr_free(&line), close(fd), false);
		}
		ft_tstr_free(&line);
		line = get_next_line(fd);
	}
	return (close(fd), all_elements_present(map) && find_player(map)
		&& validate_textures(map));
}
