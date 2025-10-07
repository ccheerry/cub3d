/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:41:32 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 03:23:58 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** has_cub_ext:
**   Comprueba que el nombre de fichero termine en ".cub".
**   Devuelve 1 si la extensión es correcta, 0 en caso contrario.
*/
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
**   Lee líneas del descriptor 'fd' hasta encontrar el comienzo del mapa.
**   - Si la línea es de elementos (NO/SO/EA/WE/F/C), llama a parse_elements().
**   - Si la línea parece de mapa, valida y delega en parse_map_grid().
**   Devuelve 1 si el mapa comienza y se parsea bien, 0 si hay error.
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
**   Punto de entrada del parseo del .cub:
**   - Verifica extensión.
**   - Abre el archivo y procesa encabezado + mapa.
**   - Comprueba que existan todos los elementos y el jugador.
**   - Valida que las texturas se cargaron correctamente.
**   Devuelve true si todo es válido, false si hay cualquier error.
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
