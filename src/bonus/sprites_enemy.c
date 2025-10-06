/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:09:41 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/06 15:56:14 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static int	project_enemy(t_game *g, int i, t_proj *out, float *perp)
{
	float	dx;
	float	dy;
	double	a;
	double	fov;

	dx = g->enemies[i].x - g->map.player.x;
	dy = -(g->enemies[i].y - g->map.player.y);
	a = atan2((double)dy, (double)dx)
		- ((double)g->map.player.angle) * M_PI / 180.0;
	pe_norm_angle(&a);
	fov = ((double)FOV) * M_PI / 180.0;
	if (fabs(a) > fov * 0.6)
		return (0);
	*perp = (float)(sqrt((double)(dx * dx + dy * dy)) * cos(a));
	if (*perp <= 0.0001f)
		return (0);
	project_calc(out, a, fov, *perp);
	return (1);
}

static void	draw_sprite_column(t_game *g, int x, t_col *col, t_img *tex)
{
	int				y;
	int				tx;
	int				ty;
	unsigned int	c;

	if (x < 0 || x >= WINDOW_WIDTH || g->zbuf[x] < 0.0001f)
		return ;
	tx = dsc_calc_tx(x, col, tex);
	y = col->y0;
	if (y < 0)
		y = 0;
	if (col->y1 > WINDOW_HEIGHT)
		col->y1 = WINDOW_HEIGHT;
	while (y < col->y1)
	{
		ty = (int)(((float)(y - col->y0) * tex->h) / (float)col->h);
		c = (unsigned int)img_px(tex, tx, ty);
		if (c != SPRITE_KEYCOLOR && g->zbuf[x] >= 0.0f)
			put_pixel(&g->frame, x, y, (int)c);
		y++;
	}
}

static int	re_project(t_game *g, t_vbuf *v)
{
	int		i;
	int		n;
	t_proj	p;

	n = 0;
	i = -1;
	while (++i < g->enemy_count && n < 256)
	{
		if (project_enemy(g, i, &p, &v->perp[n]))
		{
			v->x0[n] = p.sx0;
			v->x1[n] = p.sx1;
			v->y0[n] = p.sy0;
			v->y1[n] = p.sy1;
			v->idx[n] = n;
			n++;
		}
	}
	return (n);
}

static void	re_draw(t_game *g, t_vbuf *v, int n, t_img *tex)
{
	int		i;
	int		x;
	int		cur;
	t_col	col;

	i = -1;
	while (++i < n)
	{
		cur = v->idx[i];
		if (v->x1[cur] - v->x0[cur] <= 0 || v->y1[cur] - v->y0[cur] <= 0)
			continue ;
		col = (t_col){v->x0[cur], v->y0[cur], v->y1[cur],
			v->x1[cur] - v->x0[cur], v->y1[cur] - v->y0[cur]};
		x = v->x0[cur] - 1;
		while (++x < v->x1[cur])
		{
			if (x >= 0 && x < WINDOW_WIDTH && v->perp[cur] <= g->zbuf[x])
				draw_sprite_column(g, x, &col, tex);
		}
	}
}

void	render_enemies(t_game *g)
{
	int		n;
	t_vbuf	v;
	t_img	*tex;

	n = re_project(g, &v);
	if (n == 0)
		return (enemy_anim_tick(g));
	sort_by_dist(v.idx, v.perp, n);
	tex = &g->enemy_anim.frames[g->enemy_anim.cur];
	re_draw(g, &v, n, tex);
	enemy_anim_tick(g);
}
