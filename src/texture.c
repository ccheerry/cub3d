/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:07:12 by albcamac          #+#    #+#             */
/*   Updated: 2025/09/30 17:41:16 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** load_texture:
**   Carga una textura desde un archivo XPM y la almacena en la estructura t_img.
**   - Usa la función de MiniLibX mlx_xpm_file_to_image para abrir la textura.
**   - Rellena los campos de ancho (w), alto (h) y dirección de memoria (addr).
**   - Devuelve 1 si la carga fue exitosa, 0 en caso de error.
*/
int	load_texture(t_game *g, t_img *dst, const char *path)
{
	dst->img = mlx_xpm_file_to_image(g->mlx, (char *)path, &dst->w, &dst->h);
	if (!dst->img)
		return (0);
	dst->addr = mlx_get_data_addr(dst->img, &dst->bpp,
			&dst->line_len, &dst->endian);
	if (!dst->addr)
		return (0);
	return (1);
}
