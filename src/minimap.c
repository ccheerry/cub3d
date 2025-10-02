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

/* píxel con clipping a la imagen destino */
static void	mm_pix(t_game *g, int x, int y, int c)
{
	if (x < 0 || y < 0 || x >= g->frame.w || y >= g->frame.h)
		return ;
	put_pixel(&g->frame, x, y, c);
}

/* cuadrado sólido de tamaño MM_TILE en origen (ox,oy) */
static void	mm_square(t_game *g, int ox, int oy, int c)
{
	int	x;
	int	y;

	y = 0;
	while (y < MM_TILE)
	{
		x = 0;
		while (x < MM_TILE)
		{
			mm_pix(g, ox + x, oy + y, c);
			x++;
		}
		y++;
	}
}

/* carácter seguro del mapa; ' ' si está fuera */
static char	mm_cell(t_game *g, int tx, int ty)
{
	t_string	*row;
	size_t		len;

	if (ty < 0 || tx < 0 || ty >= (int)g->map.grid.size)
		return (' ');
	row = (t_string *)ft_vec_get(&g->map.grid, (size_t)ty);
	if (!row)
		return (' ');
	len = row->len;
	if (len && row->data[len - 1] == '\n')
		len--;
	if ((size_t)tx >= len)
		return (' ');
	return (row->data[tx]);
}

/* dibuja mapa, enemigos y jugador en la esquina superior-izquierda */
void	minimap_render(t_game *g)
{
	int		tx0;
	int		ty0;
	int		i;
	int		px;
	int		py;

	tx0 = (int)g->map.player.x - MM_W_TILES / 2;
	ty0 = (int)g->map.player.y - MM_H_TILES / 2;
	i = 0;
	while (i < MM_H_TILES)
	{
		int j = 0;
		while (j < MM_W_TILES)
		{
			char ch = mm_cell(g, tx0 + j, ty0 + i);
			px = MM_PAD + j * MM_TILE;
			py = MM_PAD + i * MM_TILE;
			if (ch == '1')
				mm_square(g, px, py, MM_COLOR_WALL);
			else
				mm_square(g, px, py, MM_COLOR_FLOOR);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < g->enemy_count)
	{
		int ex = (int)g->enemies[i].x - tx0;
		int ey = (int)g->enemies[i].y - ty0;
		if (ex >= 0 && ey >= 0 && ex < MM_W_TILES && ey < MM_H_TILES)
			mm_square(g, MM_PAD + ex * MM_TILE, MM_PAD + ey * MM_TILE,
				MM_COLOR_ENEMY);
		i++;
	}
	px = (int)g->map.player.x - tx0;
	py = (int)g->map.player.y - ty0;
	if (px >= 0 && py >= 0 && px < MM_W_TILES && py < MM_H_TILES)
		mm_square(g, MM_PAD + px * MM_TILE, MM_PAD + py * MM_TILE,
			MM_COLOR_PLAYER);
	/* pequeña “flecha” de dirección */
	i = 0;
	while (i < (MM_TILE * 2))
	{
		int dx = (int)(cos((double)g->map.player.angle * M_PI / 180.0) * (double)i);
		int dy = (int)(-sin((double)g->map.player.angle * M_PI / 180.0) * (double)i);
		mm_pix(g, MM_PAD + px * MM_TILE + MM_TILE / 2 + dx,
			MM_PAD + py * MM_TILE + MM_TILE / 2 + dy, MM_COLOR_PLAYER);
		i++;
	}
}
