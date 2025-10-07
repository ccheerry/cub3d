/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 23:19:49 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/07 14:07:19 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** is_wall:
**   Returns 1 if the map cell (x, y) is a wall or out of range.
**   Returns 0 otherwise.
*/

static int	is_wall(t_map *m, int x, int y)
{
	t_string	*row;

	if (y < 0 || y >= m->height)
		return (1);
	row = (t_string *)ft_vec_get(&m->grid, y);
	if (!row || x < 0 || x >= (int)row->len)
		return (1);
	if (row->data[x] == '1')
		return (1);
	return (0);
}

/*
** get_block_bounds:
**   Calculates the boundaries of a rectangle around position (x, y),
**   considering radius r and a small padding against walls.
**   Values are stored in the t_bounds structure.
*/

static void	get_block_bounds(float x, float y, float r, t_bounds *b)
{
	double	rr;

	rr = (double)(r + WALL_PADDING);
	b->minx = (int)floor((double)x - rr);
	b->maxx = (int)floor((double)x + rr);
	b->miny = (int)floor((double)y - rr);
	b->maxy = (int)floor((double)y + rr);
}

/*
** rect_hits_wall:
**   Iterates through cells within a rectangle (b)
*/

static int	rect_hits_wall(t_map *m, const t_bounds *b)
{
	int	i;
	int	j;

	j = b->miny;
	while (j <= b->maxy)
	{
		i = b->minx;
		while (i <= b->maxx)
		{
			if (is_wall(m, i, j))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

/*
** blocked_at:
**   Checks if position (x, y) with radius r collides with a wall.
**   Uses a collision rectangle around the position.
*/

int	blocked_at(t_map *m, float x, float y, float r)
{
	t_bounds	b;

	get_block_bounds(x, y, r, &b);
	if (rect_hits_wall(m, &b))
		return (1);
	return (0);
}
