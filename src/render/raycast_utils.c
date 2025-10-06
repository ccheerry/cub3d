/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:08:08 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/01 16:29:58 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** compute_ray_angle:
**   Calcula el ángulo del rayo correspondiente a una columna de la pantalla.
**   Usa el FOV, la posición de la columna x y el ángulo del jugador.
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
**   A partir de la distancia perpendicular (perp), calcula las posiciones
**   de inicio y fin (en píxeles) para dibujar la columna en pantalla.
**   También guarda line_height sin recortar para el texturizado correcto.
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
**   Comprueba si una celda del mapa (coordenadas mx, my) es un muro ('1').
**   Devuelve 1 si bloquea el paso, 0 en caso contrario.
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
**   Avanza un paso en el algoritmo DDA.
**   Decide si se cruza primero un eje X o Y y actualiza el lado impactado.
**   side = 0 (eje X), side = 1 (eje Y).
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
**   Calcula la distancia perpendicular final al muro impactado y
**   determina el punto exacto de impacto en el mundo (hitx, hity).
**   También aplica un "clip" mínimo para evitar distorsiones.
*/
void	finalize_hit(t_game *g, t_ray *r)
{
	float	eps;

	if (r->side == 0)
		r->perp = r->sdx - r->ddx;
	else
		r->perp = r->sdy - r->ddy;
	if (r->perp < NEAR_CLIP)
		r->perp = NEAR_CLIP;
	eps = 0.0005f;
	r->hitx = g->map.player.x + r->dirx * (r->perp - eps);
	r->hity = g->map.player.y + r->diry * (r->perp - eps);
}
