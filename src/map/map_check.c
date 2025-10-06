/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:07:04 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 18:54:47 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** all_elements_present:
**   Comprueba si todas las texturas obligatorias (N, S, E, W)
**   y los colores obligatorios (F, C) están cargados en el mapa.
**   Devuelve true si todos existen, false si falta alguno.
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
	if (map->colors.floor_r < 0 || map->colors.floor_g < 0
		|| map->colors.floor_b < 0)
		return (false);
	if (map->colors.ceiling_r < 0 || map->colors.ceiling_g < 0
		|| map->colors.ceiling_b < 0)
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
