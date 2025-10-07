/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:22:02 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 19:38:35 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** pick_wall_texture:
**   Returns the pointer to the corresponding wall texture
**   according to the hit side and ray direction.
**   - side == 0 → X axis (east/west).
**   - side == 1 → Y axis (north/south).
*/

t_img	*pick_wall_texture(t_game *g, int side, float dirx, float diry)
{
	if (side == 0)
	{
		if (dirx > 0.0f)
			return (&g->map.textures.east);
		return (&g->map.textures.west);
	}
	if (diry > 0.0f)
		return (&g->map.textures.north);
	return (&g->map.textures.south);
}

/*
** texel:
**   Returns the color (ARGB) of a texture pixel at position (tx, ty).
**   Clamps out-of-range coordinates to avoid errors.
*/

static unsigned int	texel(t_img *t, int tx, int ty)
{
	char	*px;

	if (tx < 0)
		tx = 0;
	if (ty < 0)
		ty = 0;
	if (tx >= t->w)
		tx = t->w - 1;
	if (ty >= t->h)
		ty = t->h - 1;
	px = t->addr + ty * t->line_len + tx * (t->bpp / 8);
	return (*(unsigned int *)px);
}

/*
** compute_tex_x:
**   Calculates the texture X coordinate (texx) based on
**   the ray's hit point and the side hit.
**   Adjusts to correctly reflect the wall's orientation.
*/

static int	compute_tex_x(t_img *t, const t_drawctx *ctx)
{
	double	wallx;
	int		texx;

	wallx = (double)ctx->hity;
	if (ctx->side == 1)
		wallx = (double)ctx->hitx;
	wallx = wallx - floor(wallx);
	texx = (int)(wallx * (double)t->w);
	if (ctx->side == 0 && ctx->dirx < 0.0f)
		texx = t->w - texx - 1;
	if (ctx->side == 1 && ctx->diry > 0.0f)
		texx = t->w - texx - 1;
	return (texx);
}

/*
** draw_tex_loop:
**   Iterates through the column's vertical pixels and paints each
**   one with the corresponding texture color.
**   Applies shading (darkening) on Y walls for 3D effect.
**   Uses line_height to calculate the correct texture step,
**   avoiding stretching when the wall is partially off screen.
*/

static void	draw_tex_loop(t_game *g, int x, t_img *t, const t_texloop *p)
{
	double			step;
	double			texpos;
	int				y;
	unsigned int	col;
	int				draw_start_unclipped;

	step = (double)t->h / (double)p->line_height;
	draw_start_unclipped = -p->line_height / 2 + WINDOW_HEIGHT / 2;
	texpos = (p->start - draw_start_unclipped) * step;
	y = p->start;
	while (y <= p->end)
	{
		col = texel(t, p->texx, (int)texpos);
		if (p->side != 0)
			col = (col >> 1) & 0x7F7F7F;
		put_pixel(&g->frame, x, y, (int)col);
		texpos += step;
		y++;
	}
}

/*
** draw_column_textured:
**   Main public function.
**   Prepares texture parameters for the current column
**   and calls the painting loop to render the wall on screen.
*/

void	draw_column_textured(t_game *g, int x, const t_drawctx *ctx)
{
	t_img		*t;
	int			texx;
	t_texloop	p;

	t = pick_wall_texture(g, ctx->side, ctx->dirx, ctx->diry);
	if (ctx->is_door)
		t = &g->door_tex;
	texx = compute_tex_x(t, ctx);
	p.start = ctx->start;
	p.end = ctx->end;
	p.side = ctx->side;
	p.texx = texx;
	p.line_height = ctx->line_height;
	draw_tex_loop(g, x, t, &p);
}
