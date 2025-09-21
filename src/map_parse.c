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

static char	get_char_at(t_string *row, int x)
{
	if (!row || x < 0 || x >= (int)row->len)
		return ('\0');
	return (row->data[x]);
}

static bool	is_map_surrounded(t_map *map)
{
	int			y;
	int			x;
	t_string	*row;
	t_string	*prev_row;
	t_string	*next_row;
	char		up;
	char		down;
	char		left;
	char		right;

	y = 0;
	while (y < map->height)
	{
		row = (t_string *)ft_vec_get(&map->grid, y);
		x = 0;
		while (x < (int)row->len)
		{
			if (row->data[x] == '0' || row->data[x] == 'N'
				|| row->data[x] == 'S' || row->data[x] == 'E'
				|| row->data[x] == 'W')
			{
				if (y == 0 || y == map->height - 1)
					return (false);
				prev_row = (t_string *)ft_vec_get(&map->grid, y - 1);
				next_row = (t_string *)ft_vec_get(&map->grid, y + 1);
				up = get_char_at(prev_row, x);
				down = get_char_at(next_row, x);
				left = get_char_at(row, x - 1);
				right = get_char_at(row, x + 1);
				if (up == ' ' || down == ' ' || left == ' ' || right == ' '
					|| up == '\0' || down == '\0' || left == '\0' || right == '\0'
					|| up == '\n' || down == '\n' || left == '\n' || right == '\n')
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
	size_t		i;
	t_string	line_copy;
	t_string	*ptr;

	map->grid = ft_vec(10, sizeof(t_string));
	line_copy = ft_tstr_from_cstr(first_line);
	ft_vec_push(&map->grid, &line_copy, 1);
	line = get_next_line(fd);
	while (line.len > 0)
	{
		if (is_map_line(line.data))
		{
			if (!is_valid_line(line.data))
			{
				ft_tstr_free(&line);
				i = -1;
				while (++i < map->grid.size)
				{
					ptr = (t_string *)ft_vec_get(&map->grid, i);
					ft_tstr_free(ptr);
				}
				return (ft_vec_free(&map->grid), false);
			}
			line_copy = ft_tstr_from_cstr(line.data);
			ft_vec_push(&map->grid, &line_copy, 1);
			ft_tstr_free(&line);
		}
		else
		{
			ft_tstr_free(&line);
			break ;
		}
		line = get_next_line(fd);
	}
	map->height = map->grid.size;
	if (map->height < 3)
		return (ft_vec_free(&map->grid), false);
	return (is_map_surrounded(map));
}

static bool	find_player(t_map *map)
{
	int			y;
	int			x;
	t_string	*row;

	y = 0;
	while (y < map->height)
	{
		row = (t_string *)ft_vec_get(&map->grid, y);
		x = 0;
		while (x < (int)row->len && row->data[x])
		{
			if (row->data[x] == 'N' || row->data[x] == 'S'
				|| row->data[x] == 'E' || row->data[x] == 'W')
			{
				if (map->player.orientation != 0)
					return (false);
				map->player.x = (float)x;
				map->player.y = (float)y;
				map->player.orientation = row->data[x];
				if (row->data[x] == 'N')
					map->player.angle = 0;
				else if (row->data[x] == 'S')
					map->player.angle = 180;
				else if (row->data[x] == 'E')
					map->player.angle = 90;
				else if (row->data[x] == 'W')
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
