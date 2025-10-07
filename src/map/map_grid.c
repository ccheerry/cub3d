/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:05:25 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 02:39:27 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** clear_grid_strings:
**   Libera todos los t_string almacenados en el grid del mapa y luego
**   libera también el vector dinámico que los contiene.
*/
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

/*
** push_map_line:
**   Crea un t_string a partir de una línea en C y lo añade al grid del mapa.
**   Devuelve siempre 1 (éxito).
*/
int	push_map_line(t_map *map, char *cstr_line)
{
	t_string	copy;

	copy = ft_tstr_from_cstr(cstr_line);
	ft_vec_push(&map->grid, &copy, 1);
	return (1);
}

/*
** check_no_content_after_map:
**   Verifica que después del mapa no haya más contenido.
**   Lee todas las líneas restantes y retorna 0 si encuentra cualquier
**   línea con contenido (que no sea solo '\n' o vacía).
*/
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
**   Lee todas las líneas siguientes del mapa desde el descriptor fd.
**   - Si encuentra una línea inválida, limpia el grid y devuelve 0.
**   - Si la línea es válida, la añade al grid.
**   - Termina al encontrar una línea vacía o no perteneciente al mapa.
**   - Verifica que no haya contenido después del mapa.
**   Devuelve 1 si todo fue correcto, 0 en caso de error.
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
			{
				ft_tstr_free(&line);
				return (clear_grid_strings(map), 0);
			}
			push_map_line(map, line.data);
			ft_tstr_free(&line);
		}
		else
		{
			ft_tstr_free(&line);
			if (!check_no_content_after_map(fd))
				return (clear_grid_strings(map), 0);
			break ;
		}
		line = get_next_line(fd);
	}
	return (1);
}

/*
** parse_map_grid:
**   Construye la estructura de grid del mapa a partir de la primera línea
**   y del resto leídas desde el fd.
**   - Valida cada línea.
**   - Verifica que el mapa tenga al menos 3 filas.
**   - Comprueba que esté correctamente rodeado de muros.
**   Devuelve true si el mapa es válido, false si falla alguna comprobación.
*/
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
		clear_grid_strings(map);
		return (false);
	}
	return (is_map_surrounded(map));
}
