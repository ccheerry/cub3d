/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:09:19 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 20:25:26 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	img_px(const t_img *t, int x, int y)
{
	char	*p;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= t->w)
		x = t->w - 1;
	if (y >= t->h)
		y = t->h - 1;
	p = t->addr + y * t->line_len + x * (t->bpp / 8);
	return (*(int *)p);
}
