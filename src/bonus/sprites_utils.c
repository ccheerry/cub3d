/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:52:00 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 15:52:28 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	enemy_anim_tick(t_game *g)
{
	t_anim	*a;

	a = &g->enemy_anim;
	a->ticks++;
	if (a->ticks >= ANIM_TPF)
	{
		a->ticks = 0;
		a->cur++;
		if (a->cur >= ENEMY_FRAMES)
			a->cur = 0;
	}
}

void	sort_by_dist(int *idx, float *dist, int n)
{
	int	i;
	int	swapped;
	int	tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i + 1 < n)
		{
			if (dist[idx[i]] < dist[idx[i + 1]])
			{
				tmp = idx[i];
				idx[i] = idx[i + 1];
				idx[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}

void	project_calc(t_proj *p, double a, double fov, float perp)
{
	int	sz;

	sz = (int)(WINDOW_HEIGHT / perp);
	p->sx0 = (int)((tan(a) / tan(fov * 0.5) + 1.0) * 0.5
			* WINDOW_WIDTH) - sz / 2;
	p->sx1 = p->sx0 + sz;
	p->sy0 = WINDOW_HEIGHT / 2 - sz / 2;
	p->sy1 = p->sy0 + sz;
}

void	pe_norm_angle(double *a)
{
	while (*a > M_PI)
		*a -= 2.0 * M_PI;
	while (*a < -M_PI)
		*a += 2.0 * M_PI;
}

int	dsc_calc_tx(int x, t_col *col, t_img *tex)
{
	int	tx;

	tx = (int)(((float)(x - col->x0) * tex->w) / (float)col->w);
	if (tx < 0)
		tx = 0;
	if (tx >= tex->w)
		tx = tex->w - 1;
	return (tx);
}
