/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:53:00 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 15:53:28 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

void	mm_pix(t_game *g, int x, int y, int c)
{
	if (x < 0 || y < 0 || x >= g->frame.w || y >= g->frame.h)
		return ;
	put_pixel(&g->frame, x, y, c);
}

void	mm_square(t_game *g, int ox, int oy, int c)
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

char	mm_cell(t_game *g, int tx, int ty)
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
