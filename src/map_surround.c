/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_surround.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:06:04 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/01 21:56:27 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** is_map_line:
**   Comprueba si una línea pertenece al mapa.
**   Devuelve 1 si contiene caracteres válidos del mapa
**   (0, 1, N, S, E, W o espacios). Devuelve 0 si no.
*/
int	is_map_line(char *line)
{
	int		i;
	int		has_map_char;

	if (!line || line[0] == '\0')
		return (0);
	i = 0;
	has_map_char = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'D'
			|| line[i] == 'N' || line[i] == 'S' || line[i] == 'X'
			|| line[i] == 'E' || line[i] == 'W' || line[i] == ' ')
		{
			if (line[i] != ' ')
				has_map_char = 1;
		}
		else
			return (0);
		i++;
	}
	return (has_map_char);
}

/*
** get_char_at:
**   Devuelve el caracter en la posición x de una fila (t_string).
**   Si la posición es inválida, devuelve '\0'.
*/
static char	get_char_at(t_string *row, int x)
{
	if (!row || x < 0 || x >= (int)row->len)
		return ('\0');
	return (row->data[x]);
}

/*
** cell_requires_wall:
**   Indica si una celda (0 o jugador) debe estar rodeada de muros válidos.
**   Devuelve 1 si requiere comprobación de muros, 0 en caso contrario.
*/
static int	cell_requires_wall(t_string *row, int x)
{
	char	c;

	if (!row || x < 0 || x >= (int)row->len)
		return (0);
	c = row->data[x];
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

/*
** neighbors_invalid:
**   Comprueba si alrededor de una celda caminable hay espacios vacíos
**   o caracteres inválidos (espacios, '\0', '\n').
**   Devuelve 1 si los vecinos son inválidos, 0 si todo es correcto.
*/
static int	neighbors_invalid(t_map *map, int y, int x)
{
	t_string	*row;
	char		ch;

	row = (t_string *)ft_vec_get(&map->grid, y);
	ch = get_char_at((t_string *)ft_vec_get(&map->grid, y - 1), x);
	if (ch == ' ' || ch == '\0' || ch == '\n')
		return (1);
	ch = get_char_at((t_string *)ft_vec_get(&map->grid, y + 1), x);
	if (ch == ' ' || ch == '\0' || ch == '\n')
		return (1);
	if (get_char_at(row, x - 1) == ' ' || get_char_at(row, x + 1) == ' '
		|| get_char_at(row, x - 1) == '\0' || get_char_at(row, x + 1) == '\0'
		|| get_char_at(row, x - 1) == '\n' || get_char_at(row, x + 1) == '\n')
		return (1);
	return (0);
}

/*
** is_map_surrounded:
**   Recorre todo el grid del mapa comprobando que todas las celdas
**   caminables (0 o jugador) están rodeadas por muros válidos.
**   Devuelve true si el mapa está cerrado, false en caso contrario.
*/
bool	is_map_surrounded(t_map *map)
{
	int			y;
	int			x;
	t_string	*row;

	y = 0;
	while (y < map->height)
	{
		row = (t_string *)ft_vec_get(&map->grid, y);
		x = 0;
		while (row && x < (int)row->len)
		{
			if (cell_requires_wall(row, x))
			{
				if (y == 0 || y == map->height - 1)
					return (false);
				if (neighbors_invalid(map, y, x))
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
