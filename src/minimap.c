/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:44:07 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/01 21:44:26 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static void	mm_tiles(t_game *g, int tx0, int ty0)
{
	int		i;
	int		j;
	char	ch;
	int		px;
	int		py;

	i = -1;
	while (++i < MM_H_TILES)
	{
		j = -1;
		while (++j < MM_W_TILES)
		{
			ch = mm_cell(g, tx0 + j, ty0 + i);
			px = MM_PAD + j * MM_TILE;
			py = MM_PAD + i * MM_TILE;
			if (ch == '1')
				mm_square(g, px, py, MM_COLOR_WALL);
			else
				mm_square(g, px, py, MM_COLOR_FLOOR);
		}
	}
}

static void	mm_enemies(t_game *g, int tx0, int ty0)
{
	int	i;
	int	ex;
	int	ey;

	i = -1;
	while (++i < g->enemy_count)
	{
		ex = (int)g->enemies[i].x - tx0;
		ey = (int)g->enemies[i].y - ty0;
		if (ex >= 0 && ey >= 0 && ex < MM_W_TILES && ey < MM_H_TILES)
			mm_square(g, MM_PAD + ex * MM_TILE, MM_PAD + ey * MM_TILE,
				MM_COLOR_ENEMY);
	}
}

static void	mm_player(t_game *g, int tx0, int ty0)
{
	int		px;
	int		py;
	int		i;
	int		dx;
	int		dy;

	px = (int)g->map.player.x - tx0;
	py = (int)g->map.player.y - ty0;
	if (px >= 0 && py >= 0 && px < MM_W_TILES && py < MM_H_TILES)
		mm_square(g, MM_PAD + px * MM_TILE, MM_PAD + py * MM_TILE,
			MM_COLOR_PLAYER);
	i = -1;
	while (++i < (MM_TILE * 2))
	{
		dx = (int)(cos((double)g->map.player.angle * M_PI / 180.0)
				* (double)i);
		dy = (int)(-sin((double)g->map.player.angle * M_PI / 180.0)
				* (double)i);
		mm_pix(g, MM_PAD + px * MM_TILE + MM_TILE / 2 + dx,
			MM_PAD + py * MM_TILE + MM_TILE / 2 + dy, MM_COLOR_PLAYER);
	}
}

void	minimap_render(t_game *g)
{
	int	tx0;
	int	ty0;

	tx0 = (int)g->map.player.x - MM_W_TILES / 2;
	ty0 = (int)g->map.player.y - MM_H_TILES / 2;
	mm_tiles(g, tx0, ty0);
	mm_enemies(g, tx0, ty0);
	mm_player(g, tx0, ty0);
}
