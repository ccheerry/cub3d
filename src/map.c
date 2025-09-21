/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:10:13 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/15 17:28:24 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	size_t		i;
	t_string	*ptr;

	if (map->grid.data)
	{
		i = 0;
		while (i < map->grid.size)
		{
			ptr = (t_string *)ft_vec_get(&map->grid, i);
			if (ptr)
				ft_tstr_free(ptr);
			i++;
		}
		ft_vec_free(&map->grid);
	}
	ft_tstr_free(&map->textures.north_path);
	ft_tstr_free(&map->textures.south_path);
	ft_tstr_free(&map->textures.east_path);
	ft_tstr_free(&map->textures.west_path);
	map->textures.north = NULL;
	map->textures.south = NULL;
	map->textures.east = NULL;
	map->textures.west = NULL;
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
	size_t	len;

	if (!str)
		return (str);
	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r'))
	{
		str[len - 1] = '\0';
		len--;
	}
	return (str);
}

bool	parse_elements(char *line, t_map *map, t_game *game)
{
	char	**parts;
	bool	result;
	char	*trimmed_path;

	parts = ft_split(line, ' ');
	if (!parts || !parts[0] || !parts[1])
	{
		if (parts)
			ft_free_array((void ***)&parts);
		return (false);
	}
	result = false;
	trimmed_path = trim_newline(parts[1]);
	if (ft_strcmp(parts[0], "NO") == 0 && !map->textures.north_path.data)
	{
		map->textures.north_path = ft_tstr_from_cstr(trimmed_path);
		map->textures.north = mlx_xpm_file_to_image(game->mlx,
			trimmed_path, &game->tex_width, &game->tex_height);
		result = (map->textures.north != NULL);
	}
	else if (ft_strcmp(parts[0], "SO") == 0 && !map->textures.south_path.data)
	{
		map->textures.south_path = ft_tstr_from_cstr(trimmed_path);
		map->textures.south = mlx_xpm_file_to_image(game->mlx,
			trimmed_path, &game->tex_width, &game->tex_height);
		result = (map->textures.south != NULL);
	}
	else if (ft_strcmp(parts[0], "EA") == 0 && !map->textures.east_path.data)
	{
		map->textures.east_path = ft_tstr_from_cstr(trimmed_path);
		map->textures.east = mlx_xpm_file_to_image(game->mlx,
			trimmed_path, &game->tex_width, &game->tex_height);
		result = (map->textures.east != NULL);
	}
	else if (ft_strcmp(parts[0], "WE") == 0 && !map->textures.west_path.data)
	{
		map->textures.west_path = ft_tstr_from_cstr(trimmed_path);
		map->textures.west = mlx_xpm_file_to_image(game->mlx,
			trimmed_path, &game->tex_width, &game->tex_height);
		result = (map->textures.west != NULL);
	}
	else if (ft_strcmp(parts[0], "F") == 0)
		result = parse_color(parts[1], &map->colors.floor_r,
				&map->colors.floor_g, &map->colors.floor_b);
	else if (ft_strcmp(parts[0], "C") == 0)
		result = parse_color(parts[1], &map->colors.ceiling_r,
				&map->colors.ceiling_g, &map->colors.ceiling_b);
	return (ft_free_array((void ***)&parts), result);
}

bool	validate_textures(t_map *map)
{
	return (map->textures.north && map->textures.south
		&& map->textures.east && map->textures.west);
}
