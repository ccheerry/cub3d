/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:56:48 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/01 21:56:53 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_doors_grid(t_game *g, int *count)
{
	size_t		y;
	size_t		x;
	size_t		len;
	t_string	*row;

	*count = 0;
	y = 0;
	while (y < g->map.grid.size)
	{
		row = (t_string *)ft_vec_get(&g->map.grid, y);
		if (!row)
			return (0);
		len = row->len;
		if (len && row->data[len - 1] == '\n')
			len--;
		x = 0;
		while (x < len)
		{
			if (row->data[x] == 'D')
				(*count)++;
			x++;
		}
		y++;
	}
	return (1);
}

static int	fill_doors_grid(t_game *g, t_door *list)
{
	size_t		y;
	size_t		x;
	size_t		len;
	int			i;
	t_string	*row;

	i = 0;
	y = 0;
	while (y < g->map.grid.size)
	{
		row = (t_string *)ft_vec_get(&g->map.grid, y);
		len = row ? row->len : 0;
		if (len && row->data[len - 1] == '\n')
			len--;
		x = 0;
		while (row && x < len)
		{
			if (row->data[x] == 'D')
			{
				list[i].x = (int)x;
				list[i].y = (int)y;
				list[i].t = 0.0f;
				row->data[x] = '1'; /* cerrada por defecto (bloquea) */
				i++;
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	find_doors(t_game *g)
{
	int		n;
	t_door	*arr;

	if (!count_doors_grid(g, &n))
		return (0);
	if (n == 0)
	{
		g->doors = 0;
		g->door_count = 0;
		return (1);
	}
	arr = (t_door *)ft_calloc(n, sizeof(t_door));
	if (!arr)
		return (0);
	if (!fill_doors_grid(g, arr))
		return (free(arr), 0);
	g->doors = arr;
	g->door_count = n;
	return (1);
}
