/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:13:29 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/08 14:50:04 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
** init_camera_plane:
**   Sets up the camera direction and plane vectors based on player angle.
**   The plane is perpendicular to the direction, scaled by tan(FOV/2).
*/

static void	init_camera_plane(t_game *g, t_camera *cam)
{
	double	ang;
	double	fov_rad;
	double	plane_len;

	ang = (double)g->map.player.angle * M_PI / 180.0;
	cam->dirx = (float)(-cos(ang));
	cam->diry = (float)(-sin(ang));
	fov_rad = (double)FOV * M_PI / 180.0;
	plane_len = tan(fov_rad / 2.0);
	cam->planex = (float)(-(cam->diry) * plane_len);
	cam->planey = (float)((cam->dirx) * plane_len);
}

/*
** cast_one_column:
**   Casts a ray for screen column 'x' and draws the visible wall:
**   - Uses camera plane method to calculate ray direction.
**   - Initializes/advances the DDA.
**   - No fisheye correction needed with plane method.
**   - Calculates vertical drawing boundaries (compute_bounds).
**   - Fills the texturing context and paints the column (draw_column_textured).
*/

static void	setup_ray(t_game *g, int x, t_ray *r)
{
	t_camera	cam;
	float		camerax;

	init_camera_plane(g, &cam);
	camerax = 2.0f * x / (float)WINDOW_WIDTH - 1.0f;
	r->dirx = cam.dirx + cam.planex * camerax;
	r->diry = cam.diry + cam.planey * camerax;
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
	ray_init_steps(g, r);
}

void	cast_one_column(t_game *g, int x)
{
	t_ray		r;
	t_colbounds	b;
	t_drawctx	ctx;

	setup_ray(g, x, &r);
	ray_dda(g, &r);
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
