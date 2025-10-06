/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:56:48 by albcamac          #+#    #+#             */
/*   Updated: 2025/10/02 19:37:01 by acerezo-         ###   ########.fr       */
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

static void	process_door_row(t_string *row, size_t y, t_door *list, int *i)
{
	size_t	x;
	size_t	len;

	if (!row)
		return ;
	len = row->len;
	if (len && row->data[len - 1] == '\n')
		len--;
	x = 0;
	while (x < len)
	{
		if (row->data[x] == 'D')
		{
			list[*i].x = (int)x;
			list[*i].y = (int)y;
			list[*i].t = 0.0f;
			row->data[x] = '1';
			(*i)++;
		}
		x++;
	}
}

static int	fill_doors_grid(t_game *g, t_door *list)
{
	size_t		y;
	int			i;
	t_string	*row;

	i = 0;
	y = 0;
	while (y < g->map.grid.size)
	{
		row = (t_string *)ft_vec_get(&g->map.grid, y);
		process_door_row(row, y, list, &i);
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
