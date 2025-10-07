/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:22:19 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 13:49:25 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** trim_newline:
**   Removes newline characters ('\n' or '\r') from the end of the string.
**   Returns the same pointer with the string modified in place.
*/

static char	*trim_newline(char *str)
{
	size_t	len;

	if (!str)
		return (str);
	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r'))
	{
		str[len - 1] = '\0';
		len = len - 1;
	}
	return (str);
}

/*
** get_tx_targ:
**   Based on the key ("NO", "SO", "EA", "WE"), returns the pointers
**   corresponding to the texture and path stored in the map.
*/

static int	get_tx_targ(t_map *map, char *key, t_img **out_img, t_string **path)
{
	if (ft_strcmp(key, "NO") == 0)
	{
		*out_img = &map->textures.north;
		*path = &map->textures.north_path;
		return (1);
	}
	if (ft_strcmp(key, "SO") == 0)
	{
		*out_img = &map->textures.south;
		*path = &map->textures.south_path;
		return (1);
	}
	if (ft_strcmp(key, "EA") == 0)
	{
		*out_img = &map->textures.east;
		*path = &map->textures.east_path;
		return (1);
	}
	if (ft_strcmp(key, "WE") == 0)
	{
		*out_img = &map->textures.west;
		*path = &map->textures.west_path;
		return (1);
	}
	return (0);
}

static int	apply_texture(t_game *game, t_map *map, char *key, char *path)
{
	t_img		*img;
	t_string	*spath;

	img = NULL;
	spath = NULL;
	if (!get_tx_targ(map, key, &img, &spath))
		return (0);
	if (spath->data)
	{
		ft_putstr_fd("Error\nDuplicate texture definition: ", 2);
		ft_putstr_fd(key, 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	*spath = ft_tstr_from_cstr(path);
	if (!load_texture(game, img, path))
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (-1);
	}
	return (1);
}

bool	parse_elements(char *line, t_map *map, t_game *game)
{
	char	**parts;
	char	*trimmed;
	int		result;

	parts = ft_split(line, ' ');
	if (!parts || !parts[0] || !parts[1])
	{
		ft_putstr_fd("Error\nInvalid element format\n", 2);
		if (parts)
			ft_free_array((void ***)&parts);
		return (false);
	}
	trimmed = trim_newline(parts[1]);
	result = apply_texture(game, map, parts[0], trimmed);
	if (result == 0)
		result = apply_color(map, parts[0], trimmed);
	if (result == 0)
		ft_putstr_fd("Error\nUnknown element identifier\n", 2);
	ft_free_array((void ***)&parts);
	return (result > 0);
}
