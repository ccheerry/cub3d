/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:13:29 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 15:36:59 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** ray_init_basic:
**   Inicializa los parámetros básicos del rayo:
**   - Direcciones (dirx, diry) a partir del ángulo.
**   - Celda del mapa (mapx, mapy) desde la posición del jugador.
**   - Distancias delta (ddx, ddy) para el DDA, evitando división por cero.
*/
static void	ray_init_basic(t_game *g, t_ray *r, float ang)
{
	double	dx;
	double	dy;

	dx = cos(ang);
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
**   Calcula el paso (stepx/stepy) y las distancias iniciales a la primera
**   intersección de rejilla (sdx/sdy) según el signo de la dirección del rayo.
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
**   Ejecuta el algoritmo DDA hasta impactar con un muro:
**   - Avanza paso a paso (advance_dda_step).
**   - Comprueba colisión con celda sólida (cell_blocks).
**   - Al terminar, calcula distancia perpendicular y punto de impacto
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
**   Lanza un rayo para la columna de pantalla 'x' y dibuja el muro visible:
**   - Calcula el ángulo del rayo (compute_ray_angle).
**   - Inicializa/avanza el DDA.
**   - Aplica corrección de fisheye multiplicando por cos(angle_diff).
**   - Calcula los límites verticales de dibujo (compute_bounds).
**   - Rellena el contexto de texturizado y pinta la columna (draw_column_te
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
