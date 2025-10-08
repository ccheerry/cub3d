/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:08:08 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/08 14:47:51 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** compute_ray_angle:
**   Calculates the ray angle corresponding to a screen column.
**   Uses the FOV, column x position, and player's angle.
*/

double	compute_ray_angle(t_game *g, int x)
{
	double	fov;
	double	ang;
	float	camx;

	fov = (double)FOV * M_PI / 180.0;
	ang = (double)g->map.player.angle * M_PI / 180.0;
	camx = 2.0f * x / (float)WINDOW_WIDTH - 1.0f;
	ang = ang + atan((double)camx * tan(fov / 2.0));
	return (ang);
}

/*
** compute_bounds:
**   From the perpendicular distance (perp), calculates the start and end
**   positions (in pixels) to draw the column on screen.
**   Also saves line_height unclipped for correct texturing.
*/

void	compute_bounds(float perp, t_colbounds *b)
{
	int	lineh;
	int	s;
	int	e;

	lineh = (int)(WINDOW_HEIGHT / perp);
	s = -lineh / 2 + WINDOW_HEIGHT / 2;
	e = lineh / 2 + WINDOW_HEIGHT / 2;
	if (s < 0)
		s = 0;
	if (e >= WINDOW_HEIGHT)
		e = WINDOW_HEIGHT - 1;
	b->start = s;
	b->end = e;
	b->line_height = lineh;
}

/*
** cell_blocks:
**   Checks if a map cell (coordinates mx, my) is a wall ('1').
*/

int	cell_blocks(t_map *m, int mx, int my)
{
	t_string	*row;

	if (my < 0 || my >= m->height)
		return (1);
	row = (t_string *)ft_vec_get(&m->grid, my);
	if (!row || mx < 0 || mx >= (int)row->len)
		return (1);
	if (row->data[mx] == '1')
		return (1);
	return (0);
}

/*
** advance_dda_step:
**   Advances one step in the DDA algorithm.
**   Decides whether X or Y axis is crossed first and updates the hit side.
**   side = 0 (X axis), side = 1 (Y axis).
*/

void	advance_dda_step(t_ray *r)
{
	if (r->sdx < r->sdy)
	{
		r->sdx += r->ddx;
		r->mapx += r->stepx;
		r->side = 0;
	}
	else
	{
		r->sdy += r->ddy;
		r->mapy += r->stepy;
		r->side = 1;
	}
}

/*
** finalize_hit:
**   Calculates perpendicular distance to wall using proper geometry.
**   For X-sides: distance to vertical wall at mapx or mapx+1
**   For Y-sides: distance to horizontal wall at mapy or mapy+1
*/

void	finalize_hit(t_game *g, t_ray *r)
{
	float	wall_dist;
	float	wall_x;
	float	wall_y;

	if (r->side == 0)
	{
		if (r->stepx > 0)
			wall_x = (float)r->mapx;
		else
			wall_x = (float)(r->mapx + 1);
		wall_dist = (wall_x - g->map.player.x) / r->dirx;
	}
	else
	{
		if (r->stepy > 0)
			wall_y = (float)r->mapy;
		else
			wall_y = (float)(r->mapy + 1);
		wall_dist = (wall_y - g->map.player.y) / r->diry;
	}
	r->perp = wall_dist;
	if (r->perp < NEAR_CLIP)
		r->perp = NEAR_CLIP;
	r->hitx = g->map.player.x + r->dirx * (wall_dist - 0.0005f);
	r->hity = g->map.player.y + r->diry * (wall_dist - 0.0005f);
}
