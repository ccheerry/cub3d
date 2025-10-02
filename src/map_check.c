/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:07:04 by albcamac          #+#    #+#             */
/*   Updated: 2025/09/30 17:25:05 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** all_elements_present:
**   Comprueba si todas las texturas obligatorias (N, S, E, W)
**   están cargadas en el mapa.
**   Devuelve true si todas existen, false si falta alguna.
*/
bool	all_elements_present(t_map *map)
{
	if (!map->textures.north.img)
		return (false);
	if (!map->textures.south.img)
		return (false);
	if (!map->textures.east.img)
		return (false);
	if (!map->textures.west.img)
		return (false);
	return (true);
}

/*
** validate_textures:
**   Valida que todas las texturas necesarias (N, S, E, W)
**   se hayan cargado correctamente antes de iniciar el juego.
**   Devuelve true si todas son válidas, false en caso contrario.
*/
bool	validate_textures(t_map *map)
{
	if (!map->textures.north.img)
		return (false);
	if (!map->textures.south.img)
		return (false);
	if (!map->textures.east.img)
		return (false);
	if (!map->textures.west.img)
		return (false);
	return (true);
}
