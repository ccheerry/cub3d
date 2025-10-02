/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:09:41 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 15:40:41 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

/* --- Pequeña animación por ticks --- */
static void	enemy_anim_tick(t_game *g)
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

/* ordenar idx por dist (lejos -> cerca), sin tocar dist */
static void	sort_by_dist(int *idx, float *dist, int n)
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

/* --- proyección simple (devuelve 0 si fuera de FOV/pantalla) --- */
static int	project_enemy(t_game *g, int i, int *sx0, int *sx1, int *sy0, int *sy1, float *perp)
{
	float	dx;
	float	dy;
	double	pa;
	double	a;
	double	fov;

	dx = g->enemies[i].x - g->map.player.x;
	dy = -(g->enemies[i].y - g->map.player.y);
	pa = ((double)g->map.player.angle) * M_PI / 180.0;
	a = atan2((double)dy, (double)dx) - pa;
	while (a > M_PI)
		a -= 2.0 * M_PI;
	while (a < -M_PI)
		a += 2.0 * M_PI;
	fov = ((double)FOV) * M_PI / 180.0;
	if (fabs(a) > fov * 0.6)
		return (0);
	*perp = (float)(sqrt((double)(dx * dx + dy * dy)) * cos(a));
	if (*perp <= 0.0001f)
		return (0);
	return (
		*sx0 = (int)((tan(a) / tan(fov * 0.5) + 1.0) * 0.5 * WINDOW_WIDTH) - (int)(WINDOW_HEIGHT / *perp) / 2,
		*sx1 = *sx0 + (int)(WINDOW_HEIGHT / *perp),
		*sy0 = WINDOW_HEIGHT / 2 - (int)(WINDOW_HEIGHT / *perp) / 2,
		*sy1 = *sy0 + (int)(WINDOW_HEIGHT / *perp), 1);
}

/* --- pintado de una columna del sprite con z-occlusion y colorkey --- */
static void	draw_sprite_column(t_game *g, int x, int x0, int y0, int y1, int w, int h, t_img *tex)
{
	int				y;
	int				tx;
	int				ty;
	unsigned int	c;

	if (x < 0 || x >= WINDOW_WIDTH)
		return ;
	if (g->zbuf[x] < 0.0001f)
		return ;
	tx = (int)(((float)(x - x0) * tex->w) / (float)w);
	if (tx < 0)
		tx = 0;
	if (tx >= tex->w)
		tx = tex->w - 1;
	y = y0;
	if (y < 0)
		y = 0;
	if (y1 > WINDOW_HEIGHT)
		y1 = WINDOW_HEIGHT;
	while (y < y1)
	{
		ty = (int)(((float)(y - y0) * tex->h) / (float)h);
		c = img_px(tex, tx, ty);
		if (c != SPRITE_KEYCOLOR && g->zbuf[x] >= 0.0f)
			put_pixel(&g->frame, x, y, (int)c);
		y++;
	}
}

/* --- render principal (calcula visibles, ordena y dibuja) --- */
void	render_enemies(t_game *g)
{
	int		i;
	int		n;
	t_vbuf	v;
	t_img	*tex;
	int		x;
	int		cur;

	n = 0;
	i = 0;
	while (i < g->enemy_count && n < 256)
	{
		if (project_enemy(g, i, &v.x0[n], &v.x1[n], &v.y0[n], &v.y1[n], &v.perp[n]))
		{
			v.idx[n] = n;
			n++;
		}
		i++;
	}
	if (n == 0)
		return (enemy_anim_tick(g));
	sort_by_dist(v.idx, v.perp, n);
	tex = &g->enemy_anim.frames[g->enemy_anim.cur];
	i = 0;
	while (i < n)
	{
		cur = v.idx[i];
		if (v.x1[cur] - v.x0[cur] <= 0 || v.y1[cur] - v.y0[cur] <= 0)
		{
			i++;
			continue ;
		}
		x = v.x0[cur];
		while (x < v.x1[cur])
		{
			if (x >= 0 && x < WINDOW_WIDTH && v.perp[cur] <= g->zbuf[x])
				draw_sprite_column(g, x,
					v.x0[cur], v.y0[cur], v.y1[cur],
					v.x1[cur] - v.x0[cur],
					v.y1[cur] - v.y0[cur], tex);
			x++;
		}
		i++;
	}
	enemy_anim_tick(g);
}
