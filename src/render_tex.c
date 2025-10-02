/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:22:02 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 15:31:36 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** pick_wall_texture:
**   Devuelve el puntero a la textura de muro correspondiente
**   según el lado impactado y la dirección del rayo.
**   - side == 0 → eje X (este/oeste).
**   - side == 1 → eje Y (norte/sur).
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
		return (&g->map.textures.south);
	return (&g->map.textures.north);
}

/*
** texel (privada):
**   Devuelve el color (ARGB) de un píxel de la textura en la posición (tx, ty).
**   Limita coordenadas fuera de rango para evitar errores.
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
** compute_tex_x (privada):
**   Calcula la coordenada X de la textura (texx) en función
**   del punto de impacto del rayo y el lado golpeado.
**   Ajusta para reflejar correctamente la orientación del muro.
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
	if (ctx->side == 0 && ctx->dirx > 0.0f)
		texx = t->w - texx - 1;
	if (ctx->side == 1 && ctx->diry < 0.0f)
		texx = t->w - texx - 1;
	return (texx);
}

/*
** draw_tex_loop (privada):
**   Recorre los píxeles verticales de la columna y pinta cada
**   uno con el color de la textura correspondiente.
**   Aplica sombreado (oscurece) en paredes Y para dar efecto 3D.
**   Usa line_height para calcular el paso correcto de textura,
**   evitando estiramiento cuando el muro está parcialmente fuera de pantalla.
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
**   Función pública principal.
**   Prepara los parámetros de la textura para la columna actual
**   y llama al bucle de pintado para renderizar el muro en pantalla.
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
