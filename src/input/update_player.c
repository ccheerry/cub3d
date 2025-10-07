/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:33:41 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 14:09:08 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** rotate_player:
**   Applies rotation to the player based on left or right arrow keys.
**   The rotation speed is determined by rot_speed.
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
**   Calculates movement vectors (forward and lateral) from the player's
**   current angle. Also initializes the provisional target position.
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
**   Adjusts the provisional target position according to WASD keys pressed.
**   Each key moves the player forward, backward, or strafing laterally.
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
**   Applies the calculated movement, checking collisions against walls.
**   X and Y axes are validated separately to allow sliding.
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
**   Updates the player's position and rotation based on input.
**   Includes handling of WASD keys, rotation and collisions.
**   If ESC is pressed, the game closes.
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
