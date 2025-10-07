/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:07:12 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 14:05:20 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** load_texture:
**   Loads a texture from an XPM file and stores it in the t_img structure.
**   - Fills the width (w), height (h) and memory address (addr) fields.
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
