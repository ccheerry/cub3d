/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:57:20 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 15:32:24 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static void	door_apply_cell(t_game *g, t_door *d)
{
	t_string	*row;

	row = (t_string *)ft_vec_get(&g->map.grid, (size_t)d->y);
	if (!row)
		return ;
	if (d->t >= 0.999f)
		row->data[d->x] = '0';
	else
		row->data[d->x] = '1';
}

static void	update_one_door(t_game *g, t_door *d)
{
	float	dx;
	float	dy;
	float	dist;

	dx = (d->x + 0.5f) - g->map.player.x;
	dy = (d->y + 0.5f) - g->map.player.y;
	dist = (float)sqrt((double)(dx * dx + dy * dy));
	if (dist < DOOR_PROX && d->t < 1.0f)
	{
		d->t += DOOR_SPEED;
		if (d->t > 1.0f)
			d->t = 1.0f;
	}
	else if (dist > DOOR_PROX + DOOR_HYST && d->t > 0.0f)
	{
		d->t -= DOOR_SPEED;
		if (d->t < 0.0f)
			d->t = 0.0f;
	}
	door_apply_cell(g, d);
}

int	is_door_closed_cell(t_game *g, int mx, int my)
{
	int	i;

	i = 0;
	while (i < g->door_count)
	{
		if (g->doors[i].x == mx && g->doors[i].y == my)
		{
			if (g->doors[i].t < 0.999f)
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

void	update_doors(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->door_count)
	{
		update_one_door(g, &g->doors[i]);
		i++;
	}
}
