/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:13:29 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 19:05:15 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** ray_init_basic:
**   Initializes the basic ray parameters:
**   - Directions (dirx, diry) from the angle.
**   - Map cell (mapx, mapy) from the player's position.
**   - Delta distances (ddx, ddy) for DDA, avoiding division by zero.
*/

static void	ray_init_basic(t_game *g, t_ray *r, float ang)
{
	double	dx;
	double	dy;

	dx = -cos(ang);
	dy = -sin(ang);
	r->dirx = (float)dx;
	r->diry = (float)dy;
	r->mapx = (int)g->map.player.x;
	r->mapy = (int)g->map.player.y;
	if (r->dirx == 0.0f)
		r->ddx = (float)fabs(1.0 / 1e-6);
	else
		r->ddx = (float)fabs(1.0 / r->dirx);
	if (r->diry == 0.0f)
		r->ddy = (float)fabs(1.0 / 1e-6);
	else
		r->ddy = (float)fabs(1.0 / r->diry);
}

/*
** ray_init_steps:
**   Calculates the step (stepx/stepy) and initial distances to the first
**   grid intersection (sdx/sdy) according to the ray direction's sign.
*/

static void	ray_init_steps(t_game *g, t_ray *r)
{
	if (r->dirx < 0.0f)
	{
		r->stepx = -1;
		r->sdx = (g->map.player.x - r->mapx) * r->ddx;
	}
	else
	{
		r->stepx = 1;
		r->sdx = (r->mapx + 1.0f - g->map.player.x) * r->ddx;
	}
	if (r->diry < 0.0f)
	{
		r->stepy = -1;
		r->sdy = (g->map.player.y - r->mapy) * r->ddy;
	}
	else
	{
		r->stepy = 1;
		r->sdy = (r->mapy + 1.0f - g->map.player.y) * r->ddy;
	}
}

/*
** ray_dda:
**   Executes the DDA algorithm until hitting a wall:
**   - Advances step by step (advance_dda_step).
**   - Checks collision with solid cell (cell_blocks).
**   - Upon completion, calculates perpendicular distance and hit point.
*/

static void	ray_dda(t_game *g, t_ray *r)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		advance_dda_step(r);
		if (cell_blocks(&g->map, r->mapx, r->mapy))
			hit = 1;
	}
	finalize_hit(g, r);
}

/*
** cast_one_column:
**   Casts a ray for screen column 'x' and draws the visible wall:
**   - Calculates the ray angle (compute_ray_angle).
**   - Initializes/advances the DDA.
**   - Applies fisheye correction by multiplying by cos(angle_diff).
**   - Calculates vertical drawing boundaries (compute_bounds).
**   - Fills the texturing context and paints the column (draw_column_textured).
*/

void	cast_one_column(t_game *g, int x)
{
	double		ang;
	double		player_ang;
	t_ray		r;
	t_colbounds	b;
	t_drawctx	ctx;

	ang = compute_ray_angle(g, x);
	ray_init_basic(g, &r, (float)ang);
	ray_init_steps(g, &r);
	ray_dda(g, &r);
	player_ang = (double)g->map.player.angle * M_PI / 180.0;
	r.perp = r.perp * (float)cos(ang - player_ang);
	g->zbuf[x] = r.perp;
	compute_bounds(r.perp, &b);
	ctx.start = b.start;
	ctx.end = b.end;
	ctx.line_height = b.line_height;
	ctx.side = r.side;
	ctx.dirx = r.dirx;
	ctx.diry = r.diry;
	ctx.hitx = r.hitx;
	ctx.hity = r.hity;
	ctx.is_door = is_door_closed_cell(g, r.mapx, r.mapy);
	draw_column_textured(g, x, &ctx);
}
