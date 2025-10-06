/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:33:41 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/06 21:20:59 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** rotate_player:
**   Aplica la rotación al jugador en función de las teclas de dirección
**   izquierda o derecha. La velocidad de giro está determinada por rot_speed.
*/
static void	rotate_player(t_game *g)
{
	t_player	*p;

	p = &g->map.player;
	if (g->keys.left)
		p->angle -= g->rot_speed * 180.0 / M_PI;
	if (g->keys.right)
		p->angle += g->rot_speed * 180.0 / M_PI;
}

/*
** init_move_vectors:
**   Calcula los vectores de movimiento (frontal y lateral) a partir del ángulo
**   actual del jugador. Inicializa también la posición destino provisional.
*/
static void	init_move_vectors(t_game *g, t_move *mv)
{
	t_player	*p;
	double		ang;

	p = &g->map.player;
	ang = (double)p->angle * M_PI / 180.0;
	mv->dx = (float)cos(ang);
	mv->dy = (float)(-sin(ang));
	mv->sx = -mv->dy;
	mv->sy = mv->dx;
	mv->nx = p->x;
	mv->ny = p->y;
}

/*
** accumulate_keys:
**   Ajusta la posición destino provisional según las teclas WASD pulsadas.
**   Cada tecla mueve al jugador hacia delante, atrás o en strafe lateral.
*/
static void	accumulate_keys(t_game *g, t_move *mv)
{
	if (g->keys.w)
	{
		mv->nx += mv->dx * g->move_speed;
		mv->ny += mv->dy * g->move_speed;
	}
	if (g->keys.s)
	{
		mv->nx -= mv->dx * g->move_speed;
		mv->ny -= mv->dy * g->move_speed;
	}
	if (g->keys.a)
	{
		mv->nx += mv->sx * g->move_speed;
		mv->ny += mv->sy * g->move_speed;
	}
	if (g->keys.d)
	{
		mv->nx -= mv->sx * g->move_speed;
		mv->ny -= mv->sy * g->move_speed;
	}
}

/*
** try_commit_move:
**   Aplica el movimiento calculado, comprobando colisiones contra muros.
**   Se validan los ejes X e Y por separado para permitir deslizamiento.
*/
static void	try_commit_move(t_game *g, t_move *mv)
{
	t_player	*p;

	p = &g->map.player;
	if (!blocked_at(&g->map, mv->nx, p->y, PLAYER_RADIUS))
		p->x = mv->nx;
	if (!blocked_at(&g->map, p->x, mv->ny, PLAYER_RADIUS))
		p->y = mv->ny;
}

/*
** update_player:
**   Actualiza la posición y rotación del jugador en función del input.
**   Incluye manejo de teclas WASD, rotación y colisiones.
**   Si se pulsa ESC, se cierra el juego.
*/
void	update_player(t_game *g)
{
	t_move	mv;

	rotate_player(g);
	init_move_vectors(g, &mv);
	accumulate_keys(g, &mv);
	try_commit_move(g, &mv);
	if (g->keys.esc)
		on_close(g);
}
