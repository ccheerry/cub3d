/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:22:19 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 03:28:02 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** trim_newline:
**   Elimina caracteres de salto de línea ('\n' o '\r') al final de la cadena.
**   Devuelve el mismo puntero con la cadena modificada en su lugar.
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
**   A partir de la clave ("NO", "SO", "EA", "WE"), devuelve los punteros
**   correspondientes a la textura y a la ruta almacenada en el mapa.
**   Devuelve 1 si la clave es válida, 0 en caso contrario.
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

/*
** apply_texture:
**   Carga una textura desde disco según la clave dada ("NO", "SO", "EA", "WE").
**   Guarda la ruta en el mapa y carga la imagen en memoria con load_texture().
**   Devuelve 1 si tuvo éxito, 0 en caso contrario.
*/
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
		return (0);
	}
	*spath = ft_tstr_from_cstr(path);
	if (!load_texture(game, img, path))
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (1);
}

/*
** parse_elements:
**   Interpreta una línea de la configuración del mapa (.cub).
**   - Si la línea define una textura ("NO/SO/EA/WE"), la carga.
**   - Si la línea define un color ("F" o "C"), lo aplica.
**   Devuelve true si la línea fue válida, false en caso de error.
*/
bool	parse_elements(char *line, t_map *map, t_game *game)
{
	char	**parts;
	char	*trimmed;
	int		ok;

	ok = 0;
	parts = ft_split(line, ' ');
	if (!parts || !parts[0] || !parts[1])
	{
		ft_putstr_fd("Error\nInvalid element format\n", 2);
		if (parts)
			ft_free_array((void ***)&parts);
		return (false);
	}
	trimmed = trim_newline(parts[1]);
	if (apply_texture(game, map, parts[0], trimmed))
		ok = 1;
	else if (apply_color(map, parts[0], trimmed))
		ok = 1;
	else
		ft_putstr_fd("Error\nUnknown element identifier\n", 2);
	ft_free_array((void ***)&parts);
	return (ok != 0);
}
