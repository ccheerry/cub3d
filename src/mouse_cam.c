/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:23:16 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 15:36:31 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_init(t_game *g)
{
	int	cx;
	int	cy;

	g->mouse.enabled = 1;
	cx = WINDOW_WIDTH / 2;
	cy = WINDOW_HEIGHT / 2;
	g->mouse.last_x = cx;
	g->mouse.last_y = cy;
	mlx_mouse_move(g->mlx, g->win, cx, cy);
}

int	mouse_move_hook(int x, int y, t_game *g)
{
	int	cx;
	int	cy;
	int	dx;

	(void)y;
	if (!g->mouse.enabled)
		return (0);
	cx = WINDOW_WIDTH / 2;
	cy = WINDOW_HEIGHT / 2;
	if (x == cx && y == cy)
		return (0);
	dx = x - cx;
	if (dx > -MOUSE_DEAD && dx < MOUSE_DEAD)
		dx = 0;
	if (dx > MOUSE_MAX_STEP)
		dx = MOUSE_MAX_STEP;
	if (dx < -MOUSE_MAX_STEP)
		dx = -MOUSE_MAX_STEP;
	g->map.player.angle += (float)dx * MOUSE_SENS;
	while (g->map.player.angle >= 360.0f)
		g->map.player.angle -= 360.0f;
	while (g->map.player.angle < 0.0f)
		g->map.player.angle += 360.0f;
	mlx_mouse_move(g->mlx, g->win, cx, cy);
	return (0);
}
