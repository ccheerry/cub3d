/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:09:19 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/01 20:09:24 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	img_px(const t_img *t, int x, int y)
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
	return (*(unsigned int *)p);
}
