/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:10:13 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/08 20:07:18 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_map(char *filename)
{
	t_map	temp_map;
	bool	result;

	ft_memset(&temp_map, 0, sizeof(t_map));
	result = parse_map_file(filename, &temp_map);
	free_map(&temp_map);
	return (result);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->grid)
	{
		i = -1;
		while (++i < map->height)
			if (map->grid[i])
				ft_free((void **)&map->grid[i]);
		ft_free((void **)&map->grid);
	}
	if (map->textures.north)
		ft_free((void **)&map->textures.north);
	if (map->textures.south)
		ft_free((void **)&map->textures.south);
	if (map->textures.east)
		ft_free((void **)&map->textures.east);
	if (map->textures.west)
		ft_free((void **)&map->textures.west);
}

bool	is_valid_line(char *line)
{
	int	i;

	if (!line)
		return (false);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' '
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W')
			return (false);
		i++;
	}
	return (true);
}

static bool	parse_color(char *str, int *r, int *g, int *b)
{
	char	**parts;

	parts = ft_split(str, ',');
	if (!parts || !parts[0] || !parts[1]
		|| !parts[2] || parts[3])
	{
		if (parts)
			ft_free_array((void ***)&parts);
		return (false);
	}
	*r = ft_atoi(parts[0]);
	*g = ft_atoi(parts[1]);
	*b = ft_atoi(parts[2]);
	ft_free_array((void ***)&parts);
	if (*r < 0 || *r > 255 || *g < 0
		|| *g > 255 || *b < 0 || *b > 255)
		return (false);
	return (true);
}

static char	*trim_newline(char *str)
{
	char	*trimmed;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		trimmed = ft_substr(str, 0, len - 1);
		return (trimmed);
	}
	return (ft_strdup(str));
}

bool	parse_elements(char *line, t_map *map)
{
	char	**parts;
	bool	result;

	parts = ft_split(line, ' ');
	if (!parts || !parts[0] || !parts[1])
	{
		if (parts)
			ft_free_array((void ***)&parts);
		return (false);
	}
	result = false;
	if (ft_strcmp(parts[0], "NO") == 0 && !map->textures.north)
		map->textures.north = trim_newline(parts[1]);
	else if (ft_strcmp(parts[0], "SO") == 0 && !map->textures.south)
		map->textures.south = trim_newline(parts[1]);
	else if (ft_strcmp(parts[0], "EA") == 0 && !map->textures.east)
		map->textures.east = trim_newline(parts[1]);
	else if (ft_strcmp(parts[0], "WE") == 0 && !map->textures.west)
		map->textures.west = trim_newline(parts[1]);
	else if (ft_strcmp(parts[0], "F") == 0)
		result = parse_color(parts[1], &map->colors.floor_r,
				&map->colors.floor_g, &map->colors.floor_b);
	else if (ft_strcmp(parts[0], "C") == 0)
		result = parse_color(parts[1], &map->colors.ceiling_r,
				&map->colors.ceiling_g, &map->colors.ceiling_b);
	if (parts[0][0] != 'F' && parts[0][0] != 'C')
		result = true;
	return (ft_free_array((void ***)&parts), result);
}

bool	validate_textures(t_map *map)
{
	(void)map;
	return (true);
}
