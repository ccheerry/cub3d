/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:06:32 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/01 18:05:04 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** is_player_char:
**   Devuelve 1 si el caracter es válido como posición inicial del jugador
**   ('N', 'S', 'E' o 'W'), 0 en caso contrario.
*/
static int	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

/*
** set_player_angle:
**   Ajusta el ángulo de orientación inicial del jugador en función del
**   caracter encontrado ('N', 'S', 'E', 'W').
*/
static void	set_player_angle(t_map *map, char c)
{
	if (c == 'N')
		map->player.angle = 90;
	else if (c == 'S')
		map->player.angle = 270;
	else if (c == 'E')
		map->player.angle = 0;
	else if (c == 'W')
		map->player.angle = 180;
}

/*
** handle_player_at:
**   Configura la posición y orientación del jugador en (x, y).
**   Devuelve 0 si ya había un jugador definido, 1 si se asigna correctamente.
*/
static int	handle_player_at(t_map *map, int x, int y, char c)
{
	if (map->player.orientation != 0)
	{
		ft_putstr_fd("Error\nMultiple player positions found\n", 2);
		return (0);
	}
	map->player.x = (float)x;
	map->player.y = (float)y;
	map->player.orientation = c;
	set_player_angle(map, c);
	return (1);
}

/*
** scan_row_for_player:
**   Recorre una fila del mapa buscando un caracter de jugador.
**   Si encuentra más de uno, devuelve 0 (error).
**   Si es válido, asigna la posición y orientación.
*/
static int	scan_row_for_player(t_map *map, t_string *row, int y)
{
	int	x;

	x = 0;
	while (row && x < (int)row->len && row->data[x])
	{
		if (is_player_char(row->data[x]))
		{
			if (!handle_player_at(map, x, y, row->data[x]))
				return (0);
		}
		x++;
	}
	return (1);
}

/*
** find_player:
**   Busca en todo el grid del mapa la posición inicial del jugador.
**   Actualiza map->player y map->width según el contenido del mapa.
**   Devuelve true si encuentra un único jugador válido, false en caso contrario.
*/
bool	find_player(t_map *map)
{
	int			y;
	t_string	*row;
	int			w;

	y = 0;
	while (y < map->height)
	{
		row = (t_string *)ft_vec_get(&map->grid, y);
		if (!scan_row_for_player(map, row, y))
			return (false);
		w = (int)row->len;
		if (w > map->width)
			map->width = w;
		y++;
	}
	if (map->player.orientation == 0)
	{
		ft_putstr_fd("Error\nNo player position found\n", 2);
		return (false);
	}
	return (true);
}
